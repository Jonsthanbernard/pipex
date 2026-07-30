#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *list;

    list = malloc(sizeof(t_list));
    if (!list)
        return (NULL);

    list->next = NULL;
    list->content = content;

    return (list);
}