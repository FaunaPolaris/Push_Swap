#include "llist.h"

int	dll_rlindex4(t_dllist *head, int nb1, int nb2, int nb3, int nb4)
{
	return (dll_rlindex2(head, nb1, dll_rlindex3(head, nb2, nb3, nb4)));
}
