#include "llist.h"

int	dll_dindex_has_lower(t_dllist *head, int than)
{
	while (head)
	{
		if (head->dindex < than)
			return (1);
		head = head->next;
	}
	return (0);
}
