#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*block;

	if (size != 0)
	{
		if (nmemb > SIZE_MAX / size)
			return (NULL);
	}
	block = malloc(nmemb * size);
	if (!block)
		return (NULL);
	ft_bzero(block, (nmemb * size));
	return (block);
}
