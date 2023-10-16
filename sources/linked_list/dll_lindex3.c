#include "llist.h"

int	dll_lindex3(t_dllist *head, int nb1, int nb2, int nb3)
{
	int	index;
	int	output;

	index = dll_index(head, nb1);
	output = nb1;
	if (dll_index(head, nb2) < index)
	{
		index = dll_index(head, nb2);
		output = nb2;
	}
	if (dll_index(head, nb3) < index)
	{
		index = dll_index(head, nb3);
		output = nb3;
	}
	return (output);
}
