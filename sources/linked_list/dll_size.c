#include "llist.h"

int	dll_size(t_dllist *head)
{
	int	output;

	output = 0;
	while (head)
	{
		head = head->next;
		output++;
	}
	return (output);
}
