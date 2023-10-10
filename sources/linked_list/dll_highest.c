#include "llist.h"

int	dll_highest(t_dllist *head)
{
	t_dllist	*temp;
	int		higher;

	if (!head)
		return(0);
	temp = head;
	higher = temp->as_int;;
	while (temp)
	{
		if (temp->as_int > higher)
			higher = temp->as_int;
		temp = temp->next;
	}
	return (higher);
}
