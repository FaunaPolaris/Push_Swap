#include "sorting.h"

static void	st_compare_for_swap(t_stack *a, t_stack *b);
static void	st_find_rotate(t_stack *a, t_stack *b,
		t_moves *moves, int step);
static void	st_apply_moves(t_stack *a, t_stack *b, t_moves *moves, int step);

void	sort_v2(t_stack *stack_a, t_stack *stack_b, int step)
{
	t_moves	moves;

	while (dll_has_lower(stack_a->front, step))
	{
//		stck_disp(stack_a);
//		stck_disp(stack_b);
		moves.rrb = 0;
		moves.rb = 0;
		moves.rra = 0;
		moves.ra = 0;
		moves.rrb_r = 0;
		moves.rb_r = 0;
		st_find_rotate(stack_a, stack_b, &moves, step);
		st_apply_moves(stack_a, stack_b, &moves, step);
		st_compare_for_swap(stack_a, stack_b);
//		fp_printf("------------------------\n");
	}
	if (dll_has_higher(stack_a->front, step))
		sort_v2(stack_a, stack_b, step + 50);
}

static void	st_find_rotate(t_stack *a, t_stack *b, t_moves *moves, int step)
{
	int	target_a;
	int	target_b;

	target_a = dll_next_lower(a->front, step);
//	fp_printf("target_a: %i |", target_a);
	if (b->front && a->front)
	{
		target_b = dll_closest_front(b->front, target_a);
//		fp_printf(" target_b: %i\n", target_b);
		if (dll_index(b->front, target_b) <= (dll_size(b->front) * .5) + 1)
			moves->rb = dll_index(b->front, target_b) - 1;
		else
			moves->rrb = dll_rindex(b->front, target_b);
	}
	if (a->front)
	{
		if (dll_index(a->front, target_a) <= (dll_size(a->front) * .5) + 1)
			moves->ra = dll_index(a->front, target_a) - 1;
		else
			moves->rra = dll_rindex(a->front, target_a);
	}
//	write(1, "\n", 1);
}

static void	st_apply_moves(t_stack *a, t_stack *b, t_moves *moves, int step)
{
//	fp_printf("rra: %i | rrb %i | ra %i | rb %i\n", moves->rra, moves->rrb,
//			moves->ra, moves->rb);
	while (--moves->ra >= 0)
	{
		if (--moves->rb >= 0)
		{
			stck_rott_lft_double(a, b);
			moves->rrb_r++;
		}
		else
			stck_rott_lft(a, 1);
	}
	while (--moves->rra >= 0)
	{
		if (--moves->rrb >= 0)
		{
			stck_rott_rgt_double(a, b);
			moves->rb_r++;
		}
		else
			stck_rott_rgt(a, 1);
	}
	while (--moves->rrb >= 0)
	{
		stck_rott_rgt(b, 1);
		moves->rb_r++;
	}
	while (moves->rb > 0)
	{
		stck_rott_lft(b, 1);
		moves->rb--;
		moves->rrb_r++;
	}
	if (moves->rra <= 0 && moves->rrb <= 0 && moves->ra <= 0 && moves->rb <= 0)
		stck_push(a, b);
	step -= 1;
}

static void	st_compare_for_swap(t_stack *a, t_stack *b)
{
	if (b->front && !dll_has_lower(b->front, b->front->as_int))
		stck_rott_lft(b, 1);
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
