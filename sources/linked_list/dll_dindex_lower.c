#include "llist.h"

int	dll_dindex_lower(t_dllist *head, int than)
{
	int	dindex_f;
	int	dindex_b;

	dindex_f = dll_dindex_lower_front(head, than);
	dindex_b = dll_dindex_lower_back(head, than);
	if (dindex_f < dindex_b)
		return (dll_dindex_value(head, dindex_f));
	return (dll_dindex_value(head, dindex_b));
}
