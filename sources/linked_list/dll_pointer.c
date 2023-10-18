#include "llist.h"

t_dllist	*dll_pointer(t_dllist *head, int of)
{
	t_dllist	*output;

	output = head;
	while (output)
	{
		if (output->as_int == of)
			return (output);
		output = output->next;
	}
	return (NULL);
}
