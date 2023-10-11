
#include "llist.h"

int	dll_next_higher(t_dllist *head, int than)
{
	t_dllist	*temp;

	temp = head;
	while (temp)
	{
		if (temp->as_int > than)
			return (temp->as_int);
		temp = temp->next;
	}
	return (0);
}
