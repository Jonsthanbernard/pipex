#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, const char *src)
{
	const unsigned char *psrc;
	unsigned char *pdest;
	int i;

	psrc = (const unsigned char *)src;
	pdest = (unsigned char *)dest;
	i = 0;

	while (pdest[i] < sizeof(psrc))
	{
		pdest[i] = psrc [i];
		i++;
	}
	return (char *)pdest;
}

// int main()
// {
// 	char src[] = "hello world";
// 	char dest[sizeof(src)];

// 	ft_strcpy(dest, src);
// 	printf("%s\n", dest);
// }
