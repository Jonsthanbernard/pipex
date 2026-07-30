#include "../include/pipex.h"

char	*get_env_path(char **env)
{
	if (!env)
		return (NULL);

	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			return (env[i] + 5);
		}
		i++;
	}
	return (NULL);
}

static char *ft_strnjoin(char *string1, char c, char *string2)
{
	if (!string1 || !string2)
		return (NULL);

	char	*final;
	int		i;
	int		j;

	final = malloc(ft_strlen(string1) + ft_strlen(string2) + 2);
	if (!final)
		return (NULL);
	i = 0;
	while (string1[i] != '\0')
	{
		final[i] = string1[i];
		i++;
	}
	final[i] = c;
	i++;
	j = 0;
	while (string2[j] != '\0')
	{
		final[i + j] = string2[j];
		j++;
	}
	final[i + j] = '\0';
	return (final);
}


char	*build_cmd_path(char *path, char *command)
{
	if (!path || !command)
		return (NULL);

	char	*final;
	final = ft_strnjoin(path, '/', command);

	if (access(final, X_OK) == 0)
		return (final);
	else
		return (NULL);
}

void free_array(char **arr)
{
	int i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	int		i;

	if (!cmd)
		return (NULL);
	
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	// 2. Fetch PATH string from envp
	path_env = get_env_path(envp);
	if (!path_env)
		return (NULL);

	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);

	// 3. Loop through path folders
	i = 0;
	while (paths[i] != NULL)
	{
		full_path = ft_strnjoin(paths[i], '/', cmd);
		if (full_path && access(full_path, X_OK) == 0)
		{
			free_array(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}

	free_array(paths);
	return (NULL);
}