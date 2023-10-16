#include "stack.h"

int	stck_lowest_to_front(t_stack *stack)
{
	int	lowest;
	int	i;

	lowest = dll_lowest(stack->front);
	i = 0;
	while (stack->front->as_int != lowest)
	{
		if (dll_index(stack->front, lowest)
				< (dll_size(stack->front) * .5) + 1)
			stck_rott_lft(stack, 1);
		else
			stck_rott_rgt(stack, 1);
		i++;
	}
	return (i);
}
