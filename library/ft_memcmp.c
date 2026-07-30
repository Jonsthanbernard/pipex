#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *arg, const void *arg2, size_t s)
{
	const unsigned char	*block1;
	const unsigned char	*block2;
	size_t				i;

	block1 = (const unsigned char *)arg;
	block2 = (const unsigned char *)arg2;
	i = 0;

	while (i < s)
	{
		if (block1[i] != block2[i])
			return (block1[i] - block2[i]);
		i++;
	}
	return (0);
}

// // int	main()
// // {
// // 	char str1[6] = "qwerty";
// // 	char str2[6] = "qwefgh";

// // 	printf("%d\n", memcmp(str1, str2, sizeof(str1)));
// // 	printf("%d\n", ft_memcmp(str1, str2, sizeof(str1)));
// // }

