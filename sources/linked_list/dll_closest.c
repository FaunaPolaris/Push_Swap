#include "llist.h"

int	dll_closest(t_dllist *head, int to)
{
	return (dll_lindex2(head, dll_closest_front(head, to),
				dll_closest_back(head, to)));
}
