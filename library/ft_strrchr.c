#include <stdio.h>

char	*ft_strrchr(const char *src, int c)
{

	size_t i;
	size_t NumAppear;
	size_t posSrc;

	i = 0;
	NumAppear = 0;
	posSrc = 0;

	if(!src)
	{
		return (NULL);
	}


	while (src[i] != '\0')
	{
		if (src[i] == c)
		{
			NumAppear++;
			posSrc = i;
		}
		i++;

	}
	return (char *)&src[posSrc];

}

// int main() {
// 	char str[11] = "helloworld";
// 	char *result;
// 	result = ft_strrchr(str, 'a');
// 	printf("%ld\n", result - str);
// }