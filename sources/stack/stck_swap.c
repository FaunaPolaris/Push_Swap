/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:16:29 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/06 13:16:30 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stck_swap(t_stack * stack)
{
	fp_printf("s%c\n", stack->id);
	if (!stack)
		return (0);
	if (!stack->front)
		return (0);
	if (!stack->front->next)
		return (0);
	*(int *)stack->front->value ^= *(int *)stack->front->next->value;
	*(int *)stack->front->next->value ^= *(int *)stack->front->value;
	*(int *)stack->front->value ^= *(int *)stack->front->next->value;
	return (1);
}
