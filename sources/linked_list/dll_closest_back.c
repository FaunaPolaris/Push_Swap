#include "llist.h"

int	dll_closest_back(t_dllist *head, int to)
{
	t_dllist	*temp;
	int		low_close;
	int		high_close;

	temp = dll_fnd_back(head);
	low_close = dll_lowest(head);
	high_close = dll_highest(head);
	while (temp)
	{
		if (temp->as_int > low_close && temp->as_int < to)
			low_close = temp->as_int;
		if (temp->as_int < high_close && temp->as_int > to)
			high_close = temp->as_int;
		temp = temp->prev;
	}
	if (to - low_close < high_close - to)
		return (high_close);
	return (low_close);
}
