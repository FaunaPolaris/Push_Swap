#include "sorting.h"

int	stck_push_higher(int than, t_stack *from, t_stack *to)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	j = 0;
	size = dll_size(from->front);
	while (++i <= size && from->front)
	{
		if (!dll_has_higher(from->front, than))
		{
			if (from->front->next)
				stck_swap(from, 1);
			break ;
		}
		if (from->front->as_int > than)
		{
			stck_push(from, to);
			j++;
		}
		else
			stck_rott_lft(from, 1);
	}
	return (j);
}