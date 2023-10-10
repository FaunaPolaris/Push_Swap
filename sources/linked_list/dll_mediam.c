#include "llist.h"

int	dll_mediam(t_dllist *head)
{
	int	highest;
	int	lowest;
	int	mid;
	int	i;
	int	j;

	i = 0;
	j = 0;
	highest = dll_highest(head);
	lowest = dll_lowest(head);
	mid = (highest + lowest) * .5;
	while (!dll_has(head, mid - i) && (mid - i) != 0)
		i++;
	while (!dll_has(head, mid + j) && (mid - j) != 0)
		j++;
	if (i > j)
		return (mid + j);
	return (mid - i);
}
