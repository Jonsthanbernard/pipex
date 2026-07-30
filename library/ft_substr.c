#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const unsigned char *str;
	unsigned char  *substr;
	size_t i;

	str = (const unsigned char *)s;
	substr = malloc(len*(sizeof(unsigned char))+1);
	i = 0;

	if (!str)
		return (NULL);
	
	if (!substr)
		return (NULL);

	while (i < len)
	{
		substr[i] = str[start+i];
		i++;
	}
	substr[i+1] = '\0';
	
	return (char *)substr;


}
