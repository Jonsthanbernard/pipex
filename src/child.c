#include "../include/pipex.h"

void	execute_cmd(char *cmd_str, char **envp)
{
	if (!cmd_str || !envp)
		return;

	char	**cmd_argv;
	char	*path;

	cmd_argv = ft_split(cmd_str, ' ');
	path = find_cmd_path(cmd_argv[0], envp);

	if (!cmd_argcv || !cmd_argv[0])
	{
		free_array(cmd_argv);
		exit(127);
	}

	if (!path)
	{
		ft_putstr_fd("command not found", 2);
		ft_putendl_fd(cmd_argv[0], 2);

		free_array(cmd_argv);
		exit(127);
	}

	execve(path, cmd_argv, envp);

	perror("execve");
	free(path);
	free_array(cmd_argv);
	exit(127);
}


void	child_one(char **argv, char **envp, int *pipe_fd)
{
	int	file1_fd;
	int	new_file1_fd;
	int	new_pipe_fd;

	file1_fd = open(argv[1], O_RDONLY);
	new_file1_fd = dup2(file1_fd, STDIN_FILENO);
	new_pipe_fd = dup2(pipe_fd, STDIN_FILENO);

	close(file1_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);

	execute_cmd(argv[2], envp);

	ft_putstr_fd("couldn't execute first operation (Child one)", 2);
	close(new_file1_fd);
	close(new_pipe_fd);
	exit(127);

}

void	child_two(char **argv, char **envp, int *pipe_fd)
{
	int	file1_fd;
	int	new_file1_fd;
	int	new_pipe_fd;

	file1_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	new_file1_fd = dup2(file1_fd, STDIN_FILENO);
	new_pipe_fd = dup2(pipe_fd, STDIN_FILENO);

	close(file1_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);

	execute_cmd(argv[3], envp);

	ft_putstr_fd("couldn't execute first operation (Child one)", 2);
	close(new_file1_fd);
	close(new_pipe_fd);
	exit(127);

}