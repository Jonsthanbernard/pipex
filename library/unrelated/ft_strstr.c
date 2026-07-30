#include <stdio.h>
#include <string.h>


char *ft_strstr(const char *haystack, const char *needle)
{
    size_t i;
    size_t j;

    if (*needle == '\0')
        return (char *)haystack;

    i = 0;
    while (haystack[i] != '\0')
    {
        j = 0;
        while (needle[j] && haystack[i + j] == needle[j])
            j++;

        if (needle[j] == '\0')
            return (char *)(haystack + i);

        i++;
    }
    return NULL;
}

int main (void)
{
    char *haystack = "helmhellom";
    char *needle = "hello";

    char *result = ft_strstr(haystack, needle);

    if (result != NULL)
        printf("Found at position: %ld\n", result - haystack);
    else
        printf("Not found\n");

    return 0;
}
