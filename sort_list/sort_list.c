#include "sort_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		swap;
	t_list	*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

int	ascending_order(int a, int b)
{
	return (a <= b);
}

int	main ()
{
	t_list	*list = malloc(sizeof(t_list));
	list->data = 7;
	list->next = malloc(sizeof(t_list));
	list->next->data = 3;
	list->next->next = malloc(sizeof(t_list));
	list->next->next->data = 1;
	list->next->next->next = malloc(sizeof(t_list));
	list->next->next->next->data = 4;
	list->next->next->next->next = malloc(sizeof(t_list));
	list->next->next->next->next->data = 6;
	list->next->next->next->next->next = NULL;

	printf("Before sorting: ");
	t_list *current = list;
	while (current != NULL)
	{
		printf("%d", current->data);
		current = current->next;
	}
	printf("\n");
	printf("After sorting: ");
	t_list *sorted_list = sort_list(list, ascending_order);
	while (sorted_list != NULL)
	{
		printf("%d", sorted_list->data);
		sorted_list = sorted_list->next;
	}
	printf("\n");
}
