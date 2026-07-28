#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t s)
{
	size_t i;
	size_t j;

	i = 0;

	while (haystack[i] != '\0' && s > 0) {
		j = 0;

		while (needle[j] && haystack[i + j] == needle[j])
		{
			j++;
		}

		if (needle[j] == '\0')
		{
			return ((char *)(haystack +i));
		}

		i++;
		s--;
		
	}
	return (NULL);
}

// int main()
// {
// 	char hay[14] = "zxcasdhellomm";
// 	char needle[6] = "hello";
// 	char *result = ft_strnstr(hay, needle, 14);
// 	char *resultN = strnstr(hay, needle, 14);

// 	if (result != NULL)
// 	{
// 		printf("found at position: %ld\n", result - hay);
// 	}
// 	else
// 	{
// 		printf("result not found");
// 	}
// 	if (resultN != NULL)
// 	{
// 		printf("found at position: %ld\n", resultN - hay);
// 	}
// 	else{
// 		printf("result Not found");
// 	}
// }