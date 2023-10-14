#include "llist.h"

int	dll_rindex(t_dllist *head, int of)
{
	t_dllist	*temp;
	int		i;

	i = 0;
	temp = dll_fnd_back(head);
	while (temp)
	{
		i++;
		if (temp->as_int == of)
			return (i);
		temp = temp->prev;
	}
	return (-1);
}
