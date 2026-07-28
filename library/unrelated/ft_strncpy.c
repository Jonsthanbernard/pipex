#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strncpy(char *dest, const char *src, size_t s)
{
	unsigned char *pdest;
	const unsigned char *psrc;
	size_t i;

	pdest = (unsigned char *)dest;
	psrc = (const unsigned char *)src;
	i = 0;

	while (i < s)
	{
		if (sizeof(psrc) < s && sizeof(pdest) > s)
		{
			pdest[i] = psrc[i];
			if (psrc[i] == '\0' && sizeof(pdest) > sizeof(psrc)){
				pdest[i] = '\0';
			}
		}

		else if (sizeof(psrc) >= s){
			pdest[i] = psrc[i];
		}

		i++;
	}

	return pdest;
	
}

void print_bytes(char *label, char *buf, size_t n)
{
    size_t i = 0;
    printf("%s: ", label);
    while (i < n)
    {
        if (buf[i] == '\0')
            printf("\\0 ");
        else
            printf("%c ", buf[i]);
        i++;
    }
    printf("\n");
}

int main(void)
{
    char src1[] = "hi";
    char src2[] = "hello";

    char dest1[10];
    char dest2[10];

    char dest3[10];
    char dest4[10];

    // Fill with 'X' to see what gets overwritten
    memset(dest1, 'X', 10);
    memset(dest2, 'X', 10);
    memset(dest3, 'X', 10);
    memset(dest4, 'X', 10);

    // Test 1: source shorter than n
    strncpy(dest1, src1, 5);
    ft_strncpy(dest2, src1, 5);

    print_bytes("strncpy short", dest1, 5);
    print_bytes("ft_strncpy short", dest2, 5);

    printf("\n");

    // Test 2: source longer than n
    strncpy(dest3, src2, 3);
    ft_strncpy(dest4, src2, 3);

    print_bytes("strncpy long", dest3, 3);
    print_bytes("ft_strncpy long", dest4, 3);

    return 0;
}