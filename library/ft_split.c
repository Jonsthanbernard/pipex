#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#include <stdlib.h>

static int count_words(const char *s, char c)
{
    int count = 0;
    int in_word = 0;

    while (*s)
    {
        if (*s != c && in_word == 0)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
        {
            in_word = 0;
        }
        s++;
    }
    return (count);
}

static char *extract_word(const char *s, int start, int end)
{
    char *word = malloc((end - start + 1) * sizeof(char));
    if (!word)
        return (NULL);

    int i = 0;
    while (start < end)
        word[i++] = s[start++];
    word[i] = '\0';
    return (word);
}

char **ft_split(const char *s, char c)
{
    if (!s)
        return (NULL);

    int words = count_words(s, c);
    char **result = malloc((words + 1) * sizeof(char *));
    if (!result)
        return (NULL);

    int i = 0;
    int j = 0;
    int start = -1;

    while (i <= (int)ft_strlen(s))
    {
        if (s[i] != c && s[i] != '\0' && start < 0)
        {
            start = i;
        }
        else if ((s[i] == c || s[i] == '\0') && start >= 0)
        {
            result[j++] = extract_word(s, start, i);
            start = -1;
        }
        i++;
    }
    result[j] = NULL; //

    return (result);
}