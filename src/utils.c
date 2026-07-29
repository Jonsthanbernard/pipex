#include "../include/pipex.h"

static int	count_array(char **array)
{
	if (!array)
		return (0);

	int	count;

	count = 0;

	while (array[count] != NULL)
	{
		count++;
	}

	return (count);
}

void	free_split_array(char **array)
{
	int	num_words;
	int	counter;

	num_words = count_array(array);
	counter = 0;

	while (counter < num_words)
	{
		free(array[counter]);
		counter++;
	}

	free(array);

}


void	error_exit(char *message, int fd)
{
	perror(message);
	free(fd);
	exit(0);
}