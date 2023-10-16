#include "sorting.h"

static void	st_find_rotation(t_dllist *head, int target,
		int *rotate, int *reverse_rotate);
static int	st_find_best_targeta(t_dllist *a, t_stack *stack_b, int step);

void	sortv2_rotate(t_stack *a, t_stack *b, t_moves *moves, int step)
{
	int	target_a;
	int	target_b;

	target_a = st_find_best_targeta(a->front, b, step);
	fp_printf("target_a: %i |", target_a);
	if(b->front && a->front)
	{
		target_b = dll_closest_lower(b->front, target_a);
		fp_printf(" target_b: %i\n", target_b);
		st_find_rotation(b->front, target_b, &moves->rb, &moves->rrb);
	}
	if (a->front)
		st_find_rotation(a->front, target_a, &moves->ra, &moves->rra);
	write(1, "\n", 1);
}

static void	st_find_rotation(t_dllist *head, int target,
		int *rotate, int *reverse_rotate)
{
		if (dll_index(head, target) <= (dll_size(head) * .5) + 1)
			*rotate = dll_index(head, target) - 1;
		else
			*reverse_rotate = dll_rindex(head, target);
}

static int	st_find_best_targeta(t_dllist *a, t_stack *stack_b, int step)
{
	t_dllist	*b;
	int		closest;
	int		lower;
	int		lowest;

	closest = dll_next_lower(a, step);
	lower = 0;
	lowest = 0;
	lower = dll_next_lower(a, step);
	lowest = dll_lowest(a);
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
	fp_printf("lowest in a: %i | lower in a: %i | closest in a: %i\n",
			lowest, lower, closest);
	fp_printf("smallest rindex: %i\n", dll_rindex(a, dll_rlindex3(a, closest, lower, lowest)));
	fp_printf("smallest index: %i\n", dll_index(a, dll_lindex3(a, closest, lower, lowest)));
	if (dll_rindex(a, dll_rlindex3(a, closest, lower, lowest)) <
			dll_index(a, dll_lindex3(a, closest, lower, lowest)))
		return (dll_rlindex3(a, closest, lower, lowest));
	return (dll_lindex3(a, closest, lower, lowest));
}
