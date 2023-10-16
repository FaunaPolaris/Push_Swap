#include "llist.h"

int	dll_rlindex3(t_dllist *head, int nb1, int nb2, int nb3)
{
	int	rindex;
	int	output;

	rindex = dll_rindex(head, nb1);
	output = nb1;
	if (dll_rindex(head, nb2) < rindex)
	{
		rindex = dll_rindex(head, nb2);
		output = nb2;
	}
	if (dll_rindex(head, nb3) < rindex)
	{
		rindex = dll_rindex(head, nb3);
		output = nb3;
	}
	return (output);
}
