#include "sorting.h"

void	sort_from_lower(t_stack *stack_a, t_stack *stack_b)
{
	while (dll_size(stack_a->front) > 1)
	{
		if (dll_has_lower(stack_a->front, stack_a->front->as_int))
			stck_rott_lft(stack_a, 1);
		else
			stck_push(stack_a, stack_b);
	}
	stck_push_all(stack_b, stack_a);
}
