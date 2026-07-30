#include <stdio.h>

int ft_strncmp(const char *str, const char *str2, size_t n) 
{
	const unsigned char *pstr;
	const unsigned char *pstr2;
	size_t i;

	pstr = (const unsigned char *)str;
	pstr2 = (const unsigned char *)str2;
	i = 0;

	if (n == 0)
	{
		return 0;
	}
	
	while (i < n - 1 && pstr[i] == pstr2[i] && pstr[i] != '\0')
	{
		i++;
	}

	return pstr[i] - pstr2[i];
}