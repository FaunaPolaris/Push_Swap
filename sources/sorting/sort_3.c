#include "sorting.h"

void	sort_3(t_stack *stack)
{
	if (stack->front->as_int == dll_highest(stack->front))
		stck_rott_lft(stack);
	else
		stck_swap(stack);
}
