#include <stdio.h>
#include "libft.h"

int		ft_lstsize(t_list *lst)
{
    int		num;

    num = 0;
	
    while (lst != NULL)
    {
        num++;
        lst = lst->next;
    }
    return (num);
}