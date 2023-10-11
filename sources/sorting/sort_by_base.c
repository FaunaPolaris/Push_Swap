#include "sorting.h"

static void	st_compare_for_swap(t_stack *stack_a, t_stack *stack_b);

void	sort_by_base(t_stack *stack_a, t_stack *stack_b, int base)
{
	while (dll_has_lower(stack_a->front, base))
	{
		stck_disp(stack_a);
		stck_disp(stack_b);
		st_compare_for_swap(stack_a, stack_b);
		if (stack_a->front->as_int <= base)
			stck_push(stack_a, stack_b);
		else if (dll_index(stack_a->front, 
					dll_next_lower(stack_a->front, base))
				< dll_size(stack_a->front) * .5)
			stck_rott_lft(stack_a, 1);
		else
			stck_rott_rgt(stack_a, 1);
	}
	if (base < 0 && dll_has_higher(stack_a->front, base))
		sort_by_base(stack_a, stack_b, base / 10);
	else if (base >= 0 && dll_has_higher(stack_a->front, base))
		sort_by_base(stack_a, stack_b, base * 10);
}

static void	st_compare_for_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->front && stack_a->front->next &&
			stack_b->front && stack_b->front->next)
	{
		if (stack_a->front->as_int < stack_a->front->next->as_int
				&& stack_b->front->as_int <
				stack_b->front->next->as_int)
			stck_swap_double(stack_a, stack_b);
	}
	if (stack_b->front && stack_b->front->next)
	{
		if (stack_b->front->as_int < stack_b->front->next->as_int)
			stck_swap(stack_b, 1);
	}
	if (stack_a->front && stack_a->front->next)
	{
		if (stack_a->front->as_int < stack_a->front->next->as_int)
			stck_swap(stack_a, 1);
	}
}

