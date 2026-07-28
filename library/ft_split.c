#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		number_words;
	int		i;
	int		j;
	int		k;
	int		m;

	int		len;
	int		*values;

	number_words = 0;
	i = 0;
	j = 0;
	k = 0;
	m = 0;


	while (s[i] != '\0')
	{
		if(s[i] == c)
		{
			number_words++;
		}
		i++;
	}

	values = malloc(number_words * sizeof(int));

	while (s[j] != '\0' && k < number_words) // count number of words
	{
		
		while[s[j] == c]
			j++;
		
		len = 0;
		while (s[j] && s[j] != c)
		{
			len++;
			i++;
		}

		values[k] = len;
		k++;
	}

	while (m < number_words)
	{
		result[m] = malloc(values[m] * sizeof(char *)); //allocate memory of array of poiters
		m++;
	}










}
