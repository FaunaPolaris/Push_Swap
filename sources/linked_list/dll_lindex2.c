#include "llist.h"

int	dll_lindex2(t_dllist *head, int nb1, int nb2)
{
	int	index;
	int	output;

	if (nb1 == nb2)
		return (nb1);
	index = dll_index(head, nb1);
	output = nb1;
	if (dll_index(head, nb2) < index)
	{
		index = dll_index(head, nb2);
		output = nb2;
	}
	return (output);
}
