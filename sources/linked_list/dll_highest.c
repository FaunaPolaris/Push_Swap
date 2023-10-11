#include "llist.h"

int	dll_highest(t_dllist *head)
{
	t_dllist	*temp;
	int		highest;

	if (!head)
		return(0);
	temp = head;
	highest = temp->as_int;;
	while (temp)
	{
		if (temp->as_int > highest)
			highest = temp->as_int;
		temp = temp->next;
	}
	return (highest);
}
