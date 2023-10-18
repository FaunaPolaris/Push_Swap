#include "sorting.h"

static void	st_find_rotation(t_dllist *head, int target,
		int *rotate, int *reverse_rotate);
static int	st_find_best_targeta(t_dllist *a, t_stack *stack_b, int step, int dindexer);

void	sortv2_rotate(t_stack *a, t_stack *b, t_moves *moves, int step, int dindexer)
{
	int	target_a;
	int	target_b;

	target_a = st_find_best_targeta(a->front, b, step, dindexer);
//	fp_printf("target a: %i | ", target_a);
	if(b->front && a->front)
	{
		target_b = dll_closest_lower(b->front, target_a);
//		fp_printf("target b: %i\n", target_b);
		st_find_rotation(b->front, target_b, &moves->rb, &moves->rrb);
	}
	if (a->front)
		st_find_rotation(a->front, target_a, &moves->ra, &moves->rra);
}

static void	st_find_rotation(t_dllist *head, int target,
		int *rotate, int *reverse_rotate)
{
		if (dll_index(head, target) <= (dll_size(head) * .5) + 1)
			*rotate = dll_index(head, target) - 1;
		else
			*reverse_rotate = dll_rindex(head, target);
}

static int	st_find_best_targeta(t_dllist *a, t_stack *stack_b, int step, int dindexer)
{
	t_dllist	*b;
	int		closest;
	int		lower;
	int		lowest;
	int		dindex;

	closest = dll_next_lower(a, step);
	lower = dll_next_lower(a, step);
	lowest = dll_lowest(a);
	dindex = dll_dindex_lower(a, dindexer);
	if (stack_b->front)
	{
		b = stack_b->front;
		closest = dll_closest_front(a, b->as_int);
		while (b)
		{
			closest = dll_lindex2(a, closest, dll_closest(a,
						b->as_int));
			b = b->next;
		}
	}
//	fp_printf("targets: %i | %i | %i | %i\n", closest, lower, lowest, dindex);
//	fp_printf("indexe : %i | %i | %i | %i\n", dll_index(a, closest), dll_index(a, lower), dll_index(a, lowest), dll_index(a, dindex));
//	fp_printf("rindexe: %i | %i | %i | %i\n", dll_rindex(a, closest), dll_rindex(a, lower), dll_rindex(a, lowest), dll_rindex(a, dindex));
//	fp_printf("lowest index: %i\n", dll_lindex4(a, closest, lower, lowest, dindex));
//	fp_printf("lowest rindex: %i\n", dll_rlindex4(a, closest, lower, lowest, dindex));
	if (dll_rindex(a, dll_rlindex4(a, closest, lower, lowest, dindex)) <
			dll_index(a, dll_lindex4(a, closest, lower, dindex,
					lowest)))
		return (dll_rlindex4(a, closest, lower, lowest, dindex));
	return (dll_lindex4(a, closest, lower, lowest, dindex));
}
