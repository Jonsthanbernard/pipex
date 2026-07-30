#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"


void	delete(void *arg)
{
	free(arg);
}

void	*func(void *arg)
{
	return (ft_strdup((char *)arg));
}

int	main(void)
{
	t_list	*head;
	t_list	*mapped;
	t_list	*current;

	head = NULL;

	ft_lstadd_back(&head, ft_lstnew("10"));
	ft_lstadd_back(&head, ft_lstnew("20"));
	ft_lstadd_back(&head, ft_lstnew("30"));

	mapped = ft_lstmap(head, func, delete);

	printf("Original list:\n");
	current = head;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	printf("\nMapped list:\n");
	current = mapped;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	ft_lstclear(&mapped, delete);

	return (0);
}

