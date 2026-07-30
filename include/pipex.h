//
// Created by conta on 7/29/2026.
//

#ifndef PIPEX_PIPEX_H
#define PIPEX_PIPEX_H
#include "../library/libft.h"
#include <fcntl.h>    // open
#include <stdio.h>    // perror
#include <stdlib.h>   // exit, malloc, free
#include <string.h>   // strerror
#include <sys/wait.h> // waitpid
#include <unistd.h>   // fork, pipe, dup2, execve, access, close

void free_array(char **arr);
char	*get_env_path(char **env);
char	*build_cmd_path(char *path, char *command);
char	*find_cmd_path(char *cmd, char **envp);
void	execute_cmd(char *cmd_str, char **envp);
void	child_one(char **argv, char **envp, int *pipe_fd);
void	child_two(char **argv, char **envp, int *pipe_fd);


#endif //PIPEX_PIPEX_H
