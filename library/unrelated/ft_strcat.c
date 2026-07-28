#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strcat(char *dest, const char *src )
{
	unsigned char *pdest;
	const unsigned char *psrc;
	size_t i;
	size_t a;
	size_t j;
	size_t PlaOfLastCharDest;
	size_t PlaOfLastCharSrc;

	pdest = (unsigned char *)dest;
	psrc = (const unsigned char*)src;
	i = 0;
	a = 0;
	j = 0;
	PlaOfLastCharDest = -1;

	while(pdest[i] != '\0')
	{
		i++;
	}
	PlaOfLastCharDest = i;

	while(psrc[a] != '\0')
	{
		a++;
	}
	PlaOfLastCharSrc = a;

	while (j < a)
	{
		pdest[i+j] = psrc[j];
		j++;
	}
	
	return (char *)pdest;
}

char * fft_strcat(char *dest, char *src){

	size_t dest_i;
	size_t src_i;

	if (!dest){
		return (NULL);
	}
	if (dest && !src)
		return (dest);

		
	dest_i = 0;
	while (dest[dest_i] != '\0')
	{
		dest_i++;
	}
	src_i = 0;
	while (src[src_i] != '\0'){
		dest[dest_i++] = src[src_i++];
	}
	dest[dest_i + 1] = '\0';
	return (dest);
}


int main()
{
    char dest[50] = "projet";
    char src[] = " en c !";

    printf("Before: %s\n", dest);

    fft_strcat(dest, src);

    printf("After: %s\n", dest);

    return 0;
}