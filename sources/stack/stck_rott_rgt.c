/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_rott_rgt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:43:03 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/06 16:43:04 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stck_rott_rgt(t_stack *stack)
{
	if (!stack->front || !stack->back)
		return (0);
	if (stack->front->next == stack->back)
		stck_swap(stack);
	else
	{
		stack->back->next = stack->front;
		stack->front->prev = stack->back;
		stack->front = stack->back;
		stack->back->prev->next = NULL;
		stack->back = stack->back->prev;
		stack->front->prev = NULL;
	}
	return (1);
}