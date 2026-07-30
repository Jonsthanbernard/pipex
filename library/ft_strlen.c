#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const void *str)
{
	const unsigned char *pstr;
	size_t stop;
	size_t i;

	pstr = (unsigned char*)str;
	stop = 0;
	i = 0;

	while (stop == 0)
	{
		if (pstr[i] != '\0')
		{
			i++;
		}
		else
		{
			stop = 1;
			return i;
			
		}
	}

	return (0);

}

