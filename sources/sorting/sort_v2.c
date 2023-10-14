#include "sorting.h"

static void	st_compare_for_swap(t_stack *a, t_stack *b);
static void	st_find_next_to_push(t_stack *a, t_stack *b,
		t_moves *moves);
static void	st_apply_moves(t_stack *a, t_stack *b, t_moves *moves, int step);

void	sort_v2(t_stack *stack_a, t_stack *stack_b, int step)
{
	t_moves	moves;

	while (dll_has_lower(stack_a->front, step))
	{
		moves.rrb = 0;
		moves.rb = 0;
		st_find_next_to_push(stack_a, stack_b, &moves);
		st_apply_moves(stack_a, stack_b, &moves, step);
		st_compare_for_swap(stack_a, stack_b);
//		stck_disp(stack_a);
//		stck_disp(stack_b);
	}
	if (dll_has_higher(stack_a->front, step))
		sort_v2(stack_a, stack_b, step + 75);
}

static void	st_find_next_to_push(t_stack *a, t_stack *b,
		t_moves *moves)
{
	if (b->front && a->front)
		moves->rrb = dll_index(b->front, dll_next_lower_front(b->front,
					a->front->as_int)) - 1;
	if (moves->rrb == 1 || moves->rrb == -1)
		moves->rrb = 0;
	else
		moves->rb = moves->rrb;
}

static void	st_apply_moves(t_stack *a, t_stack *b, t_moves *moves, int step)
{
	if (a->front->as_int <= step)
	{
		while (moves->rrb > 0 && moves->rrb--)
			stck_rott_lft(b, 1);
		stck_push(a, b);
		while (moves->rb > 0 && moves->rb--)
			stck_rott_rgt(b, 1);
	}
	else if (dll_index(a->front, dll_next_lower(a->front, step))
			< dll_size(a->front) * .5)
		stck_rott_lft(a, 1);
	else
	{
		if (moves->rrb)
			stck_rott_rgt_double(a, b);
		else
			stck_rott_rgt(a, 1);
	}
}

static void	st_compare_for_swap(t_stack *a, t_stack *b)
{
	if (a->front && a->front->next && b->front && b->front->next)
	{
		if (a->front->as_int > a->front->next->as_int
				&& b->front->as_int < b->front->next->as_int)
			stck_swap_double(a, b);
	}
	if (b->front && b->front->next)
	{
		if (!dll_has_lower(b->front, b->front->as_int))
			stck_rott_lft(b, 1);
		else if (b->front->as_int < b->front->next->as_int)
			stck_swap(b, 1);
	}
}
