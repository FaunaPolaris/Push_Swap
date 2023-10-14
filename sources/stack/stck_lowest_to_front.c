#include "stack.h"

int	stck_lowest_to_front(t_stack *stack)
{
	int	highest;
	int	i;

	highest = dll_highest(stack->front);
	i = 0;
	while (stack->front->as_int != highest)
	{
		if (dll_index(stack->front, highest)
				< (dll_size(stack->front) * .5) + 1)
			stck_rott_lft(stack, 1);
		else
			stck_rott_rgt(stack, 1);
		i++;
	}
	return (i);
}
