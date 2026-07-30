#include <stdio.h>
#include <ctype.h>

int ft_tolower(int c)
{
	if (c < 65 || c > 90){
		return c;
	}

	int lower[25];
	int upper[25];
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < 25)
	{
		lower[i] = 97+i;
		upper[i] = 65+i;
		i++;
	}

	while (j < c)
	{
		if (upper[j] == c)
		{
			return lower[j];
		}
		j++;
	}

	return (0);

}
