#include "../include/pipex.h"

void	execute_cmd(char *cmd_str, char **envp)
{
	if (!cmd_str || !envp)
		return;

	char	**cmd_argv;
	char	*path;

	cmd_argv = ft_split(cmd_str, ' ');
	if (!cmd_argv)
		return;

	path = find_cmd_path(cmd_argv[0], envp);

	if (!cmd_argv || !cmd_argv[0])
	{
		free_array(cmd_argv);
		exit(127);
	}

	if (!path)
	{
		ft_putstr_fd("command not found ", 2);
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


void    child_one(char **argv, char **envp, int *pipe_fd)
{
	int    file1_fd;

	// 1. Open input file (argv[1]) for reading
	file1_fd = open(argv[1], O_RDONLY);
	if (file1_fd < 0)
	{
		perror("Error opening input file ");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(1);
	}

	// 2. Redirect file1_fd to STDIN (command reads from file)
	dup2(file1_fd, STDIN_FILENO);

	// 3. Redirect STDOUT to pipe write end (command writes into pipe)
	dup2(pipe_fd[1], STDOUT_FILENO);

	// 4. Close original descriptors after duplicating
	close(file1_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);

	// 5. Execute first command (argv[2])
	execute_cmd(argv[2], envp);

	// If execute_cmd returns, execution failed
	perror("Couldn't execute first operation (Child one)");
	exit(127);
}

void    child_two(char **argv, char **envp, int *pipe_fd)
{
	int    file2_fd;

	// 1. Open destination file (argv[4]) for writing
	file2_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2_fd < 0)
	{
		perror("Error opening output file");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(1);
	}

	// 2. Redirect pipe output (read end) to STDIN (keyboard input)
	dup2(pipe_fd[0], STDIN_FILENO);

	// 3. Redirect file2_fd to STDOUT (screen output)
	dup2(file2_fd, STDOUT_FILENO);

	// 4. Close original file descriptors after dup2
	close(file2_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);

	// 5. Execute second command (argv[3])
	execute_cmd(argv[3], envp);

	// If execute_cmd returns, execution failed
	perror("Couldn't execute second operation (Child two)");
	exit(127);
}