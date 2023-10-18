#include "llist.h"

int	dll_lindex4(t_dllist *head, int nb1, int nb2, int nb3, int nb4)
{
	return (dll_lindex2(head, nb1, dll_lindex3(head, nb2, nb3, nb4)));
}
