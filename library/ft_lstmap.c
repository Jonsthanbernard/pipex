#include <stdio.h> .
#include <stdlib.h>
#include "libft.h"


t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;
	t_list	*new_node;
	void	*modificated_content;

	new_list = NULL;
	current = lst;

	while	(current != NULL)
	{
		modificated_content = f(current->content);

		new_node = ft_lstnew(modificated_content);

		if(new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			del(modificated_content);
			return (NULL);
		}

		ft_lstadd_back(&new_list, new_node);

		current = current->next;
	}

	return(new_list);
	del(modificated_content);
}
