#include "llist.h"

int	dll_dindex(t_dllist *head, int of)
{
	t_dllist	*temp;

	temp = head;
	while (temp)
	{
		if (temp->as_int == of)
			return (temp->dindex);
		temp = temp->next;
	}
	return (-1);
}
