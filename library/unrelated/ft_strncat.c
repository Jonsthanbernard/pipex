#include <stdio.h>
#include <string.h>
/*
char	*ft_strncat(char *dest, char *src, size_t n)
{
	size_t dest_i;
	size_t src_i;

	dest_i = 0;
	src_i = 0;

	if (!dest)
	{
		return NULL;
	}
	if (!src || dest)
	{
		return dest;
	}

	while (dest[dest_i] != '\0')
	{
		dest_i++;
	}

	while (src[src_i] != '\0')
	{

	}

}

*/
char * fft_strncat(char *dest, char *src, size_t n){

	size_t dest_i;
	size_t src_i;

	if (!dest){
		return (NULL);
	}
	if (dest && !src)
		return (dest);
	if (n < 1 || n > 10000)
	{
		printf("security ok\n");
		return (NULL);
	}

		
	dest_i = 0;
	while (dest[dest_i] != '\0')
	{
		dest_i++;
	}
	src_i = 0;
	while (src[src_i] != '\0' && src_i < n){
		dest[dest_i++] = src[src_i++];
	}
	dest[dest_i + 1] = '\0';
	return (dest);
}

int	main(void)
{
	char dest[50] = "hello";
	char src[6] = "world";

	fft_strncat(dest, src, 1);
	printf("%s\n", dest);
	return (0);
}