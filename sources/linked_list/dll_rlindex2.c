#include "llist.h"

int	dll_rlindex2(t_dllist *head, int nb1, int nb2)
{
	int	rindex1;
	int	rindex2;

	rindex1 = dll_rindex(head, nb1);
	rindex2 = dll_rindex(head, nb2);
	if (rindex1 < rindex2)
		return (nb1);
	return(nb2);
}
