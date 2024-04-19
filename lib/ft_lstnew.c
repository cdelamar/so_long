#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int	main(void)
{
	int *test;

	test = malloc(sizeof(int));
	*test = 42;

	t_list *new_node;
	new_node = ft_lstnew(test);

	if (new_node)
		printf("New node content: %d\n", *(int *)(new_node->content));
	else
		printf("Failed to create a new node.\n");


	free(test);
	free(new_node);

	return (0);
}*/