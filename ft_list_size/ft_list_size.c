#include <stdlib.h>
#include <stdio.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

int	main()
{
	t_list *list = malloc(sizeof(t_list));
	list->data = "Black";
	list->next = malloc(sizeof(t_list));
	list->next->data = "Red";
	list->next->next = malloc(sizeof(t_list));
	list->next->next->data = "42";
	list->next->next->next = malloc(sizeof(t_list));
	list->next->next->next->data = "Berlin";
	list->next->next->next->next = malloc(sizeof(t_list));
	list->next->next->next->next->data = "Tofu";
	list->next->next->next->next->next = NULL;

	printf("List size: %d\n", ft_list_size(list));
	return 0;
}
