#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char *ft_strjoin(const char *s1, const char *s2)
{
	const unsigned char *str1;
	const unsigned char *str2;
	unsigned char *strF;
	size_t i;
	size_t j;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	strF = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(unsigned char));
	i = 0;
	j = 0;

	malnul(str1);
	malnul(str2);
	malnul(strF);



	while (str1[i] != '\0')
	{
		strF[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		strF[i+j] = str2[j];
		j++;
	}
	strF[i+j+1] = '\0';

	return (char *)strF;
}