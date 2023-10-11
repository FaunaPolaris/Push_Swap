#include "llist.h"

int	dll_index(t_dllist *head, int of)
{
	int		i;
	t_dllist	*temp;

	temp = head;
	i = 0;
	while (temp)
	{
		i++;
		if (temp->as_int == of)
			return (i);
		temp = temp->next;
	}
	return (-1);
}
