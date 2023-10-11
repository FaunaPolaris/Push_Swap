#include "sorting.h"

int	stck_push_lower(int than, t_stack *from, t_stack *to)
{
	int	i;
	int	size;

	i = 0;
	size = dll_size(from->front);
	while (dll_has_lower(from->front, than))
	{
		if (from->front->as_int < than)
		{
			stck_push(from, to);
			i++;
		}
		else
			stck_rott_lft(from, 1);
	}
	return (i);
}
