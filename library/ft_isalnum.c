#include <stdio.h>

int	ft_isalnum(int c)
{
	if (c >= 65 && c <= 122)
	{
		return (1);
	}
	else if (c >= 0 && c <= 9)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

