#include <stdio.h>
#include <string.h>

void	*ft_memchr(void *arg, int c, size_t s)
{
	unsigned char *parg;
	unsigned char val;
	size_t i;

	parg = (unsigned char *)arg;
	val = (unsigned char)c;
	i = 0;
	
	while (i < s)
	{
		if (parg[i] == val)
			return (void *)&parg[i];
		i++;
	}
	return NULL;

}
// int main() 

// {

//     char data[] = "hello world";	
    
//     void *res1 = memchr(data, 'o', 11);
//     void *res2 = ft_memchr(data, 'o', 11);

//     printf("=== Test 1: find 'o' ===\n");
//     printf("memchr:     %p\n", res1);
//     printf("ft_memchr:  %p\n", res2);

//     if (res1 && res2)
//     {
//         printf("memchr value:    %c\n", *(char *)res1);
//         printf("ft_memchr value: %c\n", *(char *)res2);
//     }

//     printf("\n=== Test 2: not found ===\n");
//     res1 = memchr(data, 'z', 11);
//     res2 = ft_memchr(data, 'z', 11);

//     printf("memchr:     %p\n", res1);
//     printf("ft_memchr:  %p\n", res2);

//     printf("\n=== Test 3: partial search ===\n");
//     res1 = memchr(data, 'o', 4); // only "hell"
//     res2 = ft_memchr(data, 'o', 4);

//     printf("memchr:     %p\n", res1);
//     printf("ft_memchr:  %p\n", res2);

//     return 0;
	

// }