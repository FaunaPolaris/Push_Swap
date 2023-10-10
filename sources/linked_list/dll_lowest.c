#include "llist.h"

int	dll_lowest(t_dllist *head)
{
	t_dllist	*temp;
	int		lowest;

	if (!head)
		return (0);
	temp = head;
	lowest = temp->as_int;
	while (temp)
	{
		if (temp->as_int < lowest)
			lowest = temp->as_int;
		temp = temp->next;
	}
	return (lowest);
}
