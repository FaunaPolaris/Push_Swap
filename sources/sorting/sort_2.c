#include "sorting.h"

void	sort_2(t_stack *stack)
{
	if (stack->front->as_int > stack->front->next->as_int)
		stck_swap(stack, 1);
}
