#include <stdio.h>
#include <stdlib.h>
#include "libft.h"


char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		h;
	int		i;
	size_t		j;
	int		numChar;

	h = 0;
	i = 0;
	j = 0;
	numChar = 0;

	if (!s || !f)
		return NULL;

	while (s[i] != '\0')
	{
		numChar++;
		i++;
	}

	result = malloc((numChar+1) * sizeof(char));

	while(s[h] != '\0')
	{
		result[h] = s[h];
		h++;
	}
	result[h+1] = '\0';
 
	while (j < ft_strlen(s))
	{
		result[j] = f(j, result[j]);
		j++;
	}



	return (result);

}

 