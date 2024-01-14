#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list  *list_ptr;

    list_ptr = begin_list;
    while (list_ptr)
    {
        (*f)(list_ptr->data);
        list_ptr = list_ptr->next;
    }
}

void f(void *data)
{
    printf("%d ", *((int*)data));
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

int main (void)
{
	t_list *list = NULL;

	int data1 = 11;
	int data2 = 42;
	int data3 = 21;

    ft_list_push_front(&list, &data1);
    ft_list_push_front(&list, &data2);
    ft_list_push_front(&list, &data3);

    ft_list_foreach(list, f);
	printf("\n");
    return (0);
}
