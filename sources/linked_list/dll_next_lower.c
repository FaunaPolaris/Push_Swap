#include "llist.h"

int	dll_next_lower(t_dllist *head, int than)
{
	t_dllist	*temp;
	int		i;
	int		j;
	int		output;

	temp = head;
	output = 0;
	i = 0;
	j = 0;
	while (temp)
	{
		i++;
		if (temp->as_int < than)
		{
			output = temp->as_int;
			break ;
		}
		temp = temp->next;
	}
	temp = dll_fnd_back(head);
	while (temp)
	{
		j++;
		if (temp->as_int < than && j < i)
		{
			output = temp->as_int;
			break ;
		}
		temp = temp->prev;
	}
	return (output);
}
