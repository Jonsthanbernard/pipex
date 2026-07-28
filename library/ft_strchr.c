#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *src, int c)
{
	size_t src_i;

	src_i = 0;

	if (!src || !c)
	{
		return (NULL);
	}
	while(src[src_i] != '\0')
	{
		if (src[src_i] == c)
		{
			return (char *)&src[src_i];
			break;
		}
		else
		{
			src_i++;
		}
	}
	return (NULL);
}

// int main()
// {
//    char str[] = "qwertyui";
//     char *result;

//     result = ft_strchr(str, 'y');

//     if (result != NULL)
//         printf("Found at position: %ld\n", result - str);
//     else
//         printf("Character not found\n");

//     return 0;
// }