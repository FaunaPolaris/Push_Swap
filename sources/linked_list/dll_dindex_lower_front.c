#include "llist.h"

int	dll_dindex_lower_front(t_dllist *head, int than)
{
	while (head)
	{
		if (head->dindex < than)
		{
			return (head->dindex);
			break ;
		}
		head = head->next;
	}
	return (0);
}
