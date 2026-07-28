#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memset(void *arg, int c, size_t s)
{
	unsigned char *p;
	size_t i;

	p = (unsigned char*)arg;
	i = 0;
	while (i < s)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return arg;
}


int main() {
    char buf[6];

    ft_memset(buf, 'A', 5);
    buf[5] = '\0';  // null terminator

    printf("%s\n", buf);
    return 0;
}