#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);

	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}

	dup[i] = '\0';

	return (dup);
}