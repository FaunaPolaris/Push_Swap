#include "sorting.h"

static void	st_apply_moves(t_stack *a, t_stack *b, t_moves *moves);
static void	st_compare_rotation(int *first, int *secnd,
		t_stack *a, t_stack *b, int direction);

void	sort_v2(t_stack *a, t_stack *b, int step, int increment, int dindexer)
{
	t_moves	moves;

	while (dll_has_lower(a->front, step))
	{
		moves.rrb = 0;
		moves.rb = 0;
		moves.rra = 0;
		moves.ra = 0;
		sortv2_rotate(a, b, &moves, step, dindexer);
		st_apply_moves(a, b, &moves);
	}
	if (dll_has_higher(a->front, step))
		sort_v2(a, b, step + increment, increment, dindexer + increment);
}

static void	st_apply_moves(t_stack *a, t_stack *b, t_moves *moves)
{
	st_compare_rotation(&moves->ra, &moves->rb, a, b, 1);
	st_compare_rotation(&moves->rra, &moves->rrb, a, b, 0);
	while (--moves->rrb >= 0)
		stck_rott_rgt(b, 1);
	while (--moves->rb >= 0)
		stck_rott_lft(b, 1);
	if (moves->rra <= 0 && moves->rrb <= 0 &&
			moves->ra <= 0 && moves->rb <= 0)
		stck_push(a, b);
}

static void	st_compare_rotation(int *first, int *secnd,
		t_stack *a, t_stack *b, int direction)
{
	while (--*first >= 0)
	{
		if (--*secnd >= 0)
		{
			if (direction)
				stck_rott_lft_double(a, b);
			else
				stck_rott_rgt_double(a, b);
		}
		else if (direction)
			stck_rott_lft(a, 1);
		else
			stck_rott_rgt(a, 1);
	}
}
