#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t length)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	i = 0;

	while (dest_len < length && dest[dest_len] != '\0')
		dest_len++;

	src_len = strlen(src);

	if (dest_len == length)
		return (length + src_len);

	while (src[i] != '\0' && (dest_len + i) < (length - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}

	if (dest_len < length)
		dest[dest_len + i] = '\0';

	return (dest_len + src_len);
}
