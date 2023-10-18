#include "sorting.h"

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	highest;

	highest = dll_highest(stack_a->front);
	if (dll_index(stack_a->front, highest) == 3)
	{
		stck_rott_lft(stack_a, 1);
		stck_rott_lft(stack_a, 1);
	}
	else if (dll_index(stack_a->front, highest) == 2)
		stck_swap(stack_a, 1);
	else if (dll_index(stack_a->front, highest) == 5)
		stck_rott_rgt(stack_a, 1);
	else if (dll_index(stack_a->front, highest) == 4)
	{
		stck_rott_rgt(stack_a, 1);
		stck_rott_rgt(stack_a, 1);
	}
	stck_push(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	stck_push(stack_b, stack_a);
	stck_rott_lft(stack_a, 1);
}
