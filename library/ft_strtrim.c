#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	in_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*result;
	int		start;
	int		end;
	int		a;

	if (!s1 || !set)
		return (NULL);

	start = 0;
	end = ft_strlen(s1) - 1;

	while (s1[start] && in_set(s1[start], set))
		start++;

	while (end >= start && in_set(s1[end], set))
		end--;

	result = malloc((end - start + 2) * sizeof(char));
	if (!result)
		return (NULL);

	a = 0;
	while (start <= end)
	{
		result[a] = s1[start];
		a++;
		start++;
	}

	result[a] = '\0';

	return (result);
}