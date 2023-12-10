#include <stdlib.h>
#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	swap = 0;
	t_list	*head = lst;

	while (lst->next != 0)
	{
		if (((*cmp)(lst->data, lst->next->data)) != 0)
			lst = lst->next;
		else
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = head;
	}
	lst = head;
	return (lst);
}

// int ascending(int a, int b)
// {
// 	return (a <= b); // --> true = 1 -> ascending
// 					// --> false = 0 -> descending
// }
// int descending(int a, int b)
// {
// 	return (a >= b); // --> true = 1 -> descending
// 					// --> false = 0 -> ascending
// }

// #include <stdlib.h>
// #include "list.h"

// t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
// {
// 	int	swap;
// 	t_list	*tmp;

// 	tmp = lst;
// 	while(lst->next != NULL)
// 	{
// 		if (((*cmp)(lst->data, lst->next->data)) == 0)
// 		{
// 			swap = lst->data;
// 			lst->data = lst->next->data;
// 			lst->next->data = swap;
// 			lst = tmp;
// 		}
// 		else
// 			lst = lst->next;
// 	}
// 	lst = tmp;
// 	return (lst);
// }