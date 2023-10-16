#include "llist.h"

int		dll_closest_lower(t_dllist *head, int to)
{
	t_dllist	*temp;
	int		low_close;

	temp = head;
	low_close = dll_lowest(head);
	if (!dll_has_lower(head, to))
		return (dll_highest(head));
	while (temp)
	{
		if (temp->as_int > low_close && temp->as_int < to)
			low_close = temp->as_int;
		temp = temp->next;
	}
	return (low_close);
}
