#include <stdio.h>
#include <stdlib.h>
#include "libft.h"



void ft_lstclear(t_list **lst, void (*del)(void *))
{

	if (lst == NULL || *lst == NULL)
		return;


	t_list	*next; //address for the next node
	t_list	*current; //address for the current node

	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}