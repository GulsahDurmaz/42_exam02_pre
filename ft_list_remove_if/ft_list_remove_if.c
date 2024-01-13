#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_list *cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	cur = *begin_list;
	ft_list_remove_if(&cur->next, data_ref, cmp);
}

int compare_int(void *a, void *b)
{
	return *((int*)a) - *((int*)b);
}
void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (new_node == NULL)
        return;
    new_node->data = data;
    new_node->next = *begin_list;
    *begin_list = new_node;
}

int main()
{
	t_list *list = NULL;

	int data1 = 11;
	int data2 = 42;
	int data3 = 21;

    ft_list_push_front(&list, &data1);
    ft_list_push_front(&list, &data2);
    ft_list_push_front(&list, &data3);

    printf("Before removing: ");
	t_list *current = list;
	while (current != NULL)
	{
		printf("%d", *((int*)current->data));
		current = current->next;
	}
	printf("\n");

	t_list *after = list;
    int value_to_remove = 42;
    ft_list_remove_if(&after, &value_to_remove, compare_int);

    printf("After removing: ");
	while (after != NULL)
	{
		printf("%d", *((int*)after->data));
		after = after->next;
	}
	printf("\n");
	while (list != NULL)
	{
		t_list *temp = list;
		list = list->next;
		free(temp);
	}
	return 0;
}
