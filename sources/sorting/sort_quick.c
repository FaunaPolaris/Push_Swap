/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:35:22 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/10 13:59:57 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	sort_quick(t_stack *stack_a, t_stack *stack_b)
{
	int		size;

	if (!stack_a || !stack_b)
		return ;
	size = dll_size(stack_a->front);
	if (size == 0 || size == 1)
		return ;
	if (size == 2)
	{
		if (stack_a->front->as_int > stack_a->front->next->as_int)
			stck_swap(stack_a, 1);
		return ;
	}

	sort_from_lower(stack_a, stack_b);
	sort_from_lower(stack_b, stack_a);
	stck_push_all(stack_b, stack_a);
}

