#include "../include/pipex.h"

int main (int argc, char **argv, char **envp)
{
	if (argc > 5)
		return (1);

	pid_t	pid1;
	pid_t	pid2;
	int		pipe_fd[2];

	pipe(pipe_fd);

	// 2. First Fork -> Child 1
	pid1 = fork();
	if (pid1 == 0)
		child_one(argv, envp, pipe_fd);

	// 3. Second Fork -> Child 2
	pid2 = fork();
	if (pid2 == 0)
		child_two(argv, envp, pipe_fd);

	// 4. Parent closes pipe ends and waits for both children
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}