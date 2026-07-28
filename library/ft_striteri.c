#include <stdio.h>

void    fff(unsigned int i, char *c)
{
    (void)i;

    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

void    ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int    i;

    i = 0;
    while (s[i] != '\0')
    {
        f(i, &s[i]);
        i++;
    }
}
int main()
{
	char str[] = "hello";

	ft_striteri(str, fff);

	printf("%s\n", str);
}