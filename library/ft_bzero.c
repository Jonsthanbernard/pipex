#include <stdio.h>
#include <stdlib.h>

void	ft_bzero(void *arg, size_t s)
{
	unsigned char	*parg;
	size_t			t;

	parg = (unsigned char *)arg;
	t = 0;
	while (t < s)
	{
		parg[t] = 0;
		t++;
	}
}
