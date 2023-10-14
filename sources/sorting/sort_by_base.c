/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:56:41 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/12 09:56:42 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static void	st_compare_for_swap(t_stack *stack_a, t_stack *stack_b);
static void	st_check_order(t_stack *stack_a, t_stack *stack_b, int rot);

void	sort_by_base(t_stack *stack_a, t_stack *stack_b, int base)
{
	while (dll_has_lower(stack_a->front, base))
	{
		if (stack_a->front->as_int <= base)
		{
			st_check_order(stack_a, stack_b, 1);
			stck_push(stack_a, stack_b);
			st_check_order(stack_a, stack_b, 0);
		}
		else if (dll_index(stack_a->front, 
					dll_next_lower(stack_a->front, base))
				< dll_size(stack_a->front) * .5)
			stck_rott_lft(stack_a, 1);
		else
			stck_rott_rgt(stack_a, 1);
		if (stack_b->front && !dll_has_lower(stack_b->front,
					stack_b->front->as_int))
			stck_rott_lft(stack_b, 1);
		st_compare_for_swap(stack_a, stack_b);
	}
	if (base < 0 && dll_has_higher(stack_a->front, base))
		sort_by_base(stack_a, stack_b, base / 10);
	else if (base >= 0 && dll_has_higher(stack_a->front, base))
		sort_by_base(stack_a, stack_b, base += 30);
}

static void	st_check_order(t_stack *stack_a, t_stack *stack_b, int rot)
{
	int		position;
	static int	walk_back;

	if (stack_b->front && stack_a->front)
		position = dll_index(stack_b->front,
				dll_next_lower_front(stack_b->front,
					stack_a->front->as_int)) - 1;
	else
		return ;
	if (position == 1 || position == -1)
		return ;
	if (rot && position >= 0)
	{
		walk_back = position;
		while (position--)
			stck_rott_lft(stack_b, 1);
	}
	else if (walk_back > 0)
	{
		while (walk_back--)
			stck_rott_rgt(stack_b, 1);
	}
	return ;
}

static void	st_compare_for_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->front && stack_a->front->next &&
			stack_b->front && stack_b->front->next)
	{
		if (stack_a->front->as_int > stack_a->front->next->as_int
				&& stack_b->front->as_int <
				stack_b->front->next->as_int)
			stck_swap_double(stack_a, stack_b);
	}
	if (stack_b->front && stack_b->front->next)
	{
		if (stack_b->front->as_int < stack_b->front->next->as_int)
			stck_swap(stack_b, 1);
	}
}

