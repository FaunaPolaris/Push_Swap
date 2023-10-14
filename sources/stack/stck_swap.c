/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:16:29 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/07 16:53:41 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stck_swap(t_stack *stack, int print)
{
	int	temp;

	if (!stack || !stack->front || !stack->front->next)
		return (0);
	temp = stack->front->next->as_int;
	stack->front->next->as_int = stack->front->as_int;
	stack->front->as_int = temp;
	if (print)
		fp_printf("s%c\n", stack->id);
	return (1);
}
