/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:35:22 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/09 18:18:08 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static int	st_find_pivot(t_stack *stack_a, int mid)
{
	t_dllist	*temp;
	
	if (!stack_a->front->next)
		return (stack_a->front->as_int);
	temp = stack_a->front;
	while (mid--)
		temp = temp->next;
	return (temp->as_int);
}

void	sort_quick(t_stack *stack_a, t_stack *stack_b)
{
	int		pivot;
	int		size;
	int		i;

	if (!stack_a || !stack_b)
		return ;
	i = -1;
	size = dll_size(stack_a->front);
	if (size == 0 || size == 1)
		return ;
	pivot = st_find_pivot(stack_a, size * .5);
	fp_printf("pivot: %i\n", pivot);
	while (++i <= size)
	{
		if (!dll_has_lower(stack_a->front, pivot))
		{
			if (stack_a->front->next)
			{
				stck_swap(stack_a);
				fp_putendl_fd("sa", 1);
			}
			break ;
		}
		if (stack_a->front->as_int < pivot)
		{
			stck_push(stack_a, stack_b);
			fp_putendl_fd("pb", 1);
		}
		else
		{
			stck_rott_lft(stack_a);
			fp_putendl_fd("ra", 1);
		}
	}
	stck_disp(stack_a);
	stck_disp(stack_b);
	if (stack_a->front->next)
		sort_quick(stack_a, stack_b);
}
