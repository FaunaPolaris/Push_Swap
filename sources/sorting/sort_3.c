#include "sorting.h"

void	sort_3(t_stack *stack)
{
	int	highest;

	highest = dll_highest(stack->front);
	if (dll_index(stack->front, highest) == 1)
		stck_rott_lft(stack, 1);
	else if (dll_index(stack->front, highest) == 2)
		stck_rott_rgt(stack, 1);
	if (stack->front->as_int > stack->front->next->as_int)
		stck_swap(stack, 1);
}
