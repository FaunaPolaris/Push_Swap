#include "llist.h"

int		dll_closest_front(t_dllist *head, int to)
{
	t_dllist	*temp;
	int		low_close;
	int		high_close;

	temp = head;
	low_close = 0;
	high_close = dll_highest(head);
	while (temp)
	{
		if (temp->as_int > low_close && temp->as_int < to)
			low_close = temp->as_int;
		if (temp->as_int < high_close && temp->as_int > to)
			high_close = temp->as_int;
		temp = temp->next;
	}
	if (to - low_close < high_close - to)
		return (high_close);
	return (low_close);
}
