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
	if (!string1 || !c || !string2)
		return (NULL);

	char	*final;
	int		i;
	int		j;

	final = malloc((ft_strlen(string1) + ft_strlen(string2) + 2) * sizeof(char));
	i = 0;

	while (string1[i] != "\n")
	{
		final[i] = string1[i];
		i++;
	}
	i++;
	final[i] = c;

	j = 0;
	while (string2[j] != "\n")
	{
		final[i] = string2[j];
		i++;
		j++;
	}
	final[i+1] = "\n";
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

char	*find_cmd_path(const char *cmd, char **envp)
{
	if (cmd && (cmd[0] == "/" || cmd[0] == "."))
		return(ft_strdup(cmd));
	return (NULL);

	char	*path_env;
	char	**paths;
	char	*full_path;
	int		i;

	path_env = get_env_path(envp);
	if (!path_env)
		return (NULL);

	paths = ft_split(path_env, ':');

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
	return(NULL);
}