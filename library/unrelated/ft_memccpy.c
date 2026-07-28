#include <stdio.h>
#include <string.h>

void    *ft_memccpy(void *dst, const void *src, int c, size_t s)
{
    const unsigned char *psrc;
    unsigned char *pdst;
    size_t i;

    psrc = (unsigned char*)src;
	pdst = (unsigned char*)dst;
	

	i = 0;

	while (i<s)
	{
		if (psrc[i] != c)
		{
			pdst[i] = psrc[i];
			i++;
		}
		else
		{
			break;
		}
	}
	return dst;
}	

int main() 
{
	char al[5] = "abcde";
	char dest[5];

	
	ft_memccpy(dest, al, 'd', sizeof(al));
	for (size_t i = 0; i < sizeof(al); i++)
	{
		printf("%c\n", dest[i]);
	}
}