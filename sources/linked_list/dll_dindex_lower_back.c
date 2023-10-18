#include "llist.h"

int	dll_dindex_lower_back(t_dllist *head, int than)
{
	head = dll_fnd_back(head);
	while (head)
	{
		if (head->dindex < than)
		{
		return (head->dindex);
			break ;
		}
		head = head->prev;
	}
	return (0);
}
