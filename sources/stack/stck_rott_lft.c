/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_rott_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:38:04 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/06 16:38:05 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stck_rott_lft(t_stack *stack)
{
	if (!stack->back || !stack->front)
		return (0);
	if (stack->front->next == stack->back)
		stck_swap(stack);
	else
	{
		stack->front->prev = stack->back;
		stack->back->next = stack->front;
		stack->front = stack->front->next;
		stack->front->prev = NULL;
		stack->back = stack->back->next;
		stack->back->next = NULL;
	}
	return (1);
}
