#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t s)
{
	unsigned char *pdst;
	const unsigned char *psrc;
	size_t i;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = 0;

	while(i<s){
		pdst[i] = psrc[i];
		i++;
	}

	return dst;

}	

// int	main()
// {
// 	char srcc;
// 	char dest;
// 	char *psrcc;
// 	char *pdest;

// 	srcc = 'c';
// 	psrcc = &srcc;
// 	pdest = &dest;
// 	ft_memcpy(pdest, psrcc, 1);
// 	printf("%c\n", dest);
// }