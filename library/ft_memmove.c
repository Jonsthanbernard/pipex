#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t s)
{
	unsigned char *pdest;
	const unsigned char *psrc;
	size_t i;

	pdest = (unsigned char*)dest;
	psrc = (unsigned char*)src;
	i = 0;

	if (pdest < psrc)
	{
		while (i < s)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	else
	{
		i = s;
		while (i > 0)
		{
			pdest[i-1] = psrc[i-1];
			i--;
		}

	}
	return dest;

}
