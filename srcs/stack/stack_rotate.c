/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:56:05 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/07 18:37:57 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

int	stack_rotate(t_stack *stack)
{
	if (!stack->btm)
	{
		ft_putstr_fd("Error: stack btm is undefined!", 2);
		return (0);
	}
	if (stack->top)
	{	
		if (stack->top->next == stack->btm)
			swap_stack(stack);
		else
		{
			stack->btm->next = stack->top;
			stack->top->prev = stack->btm;
			stack->top = stack->btm;
			stack->top->prev->next = NULL;
			stack->btm = stack->btm->prev;
			stack->top->prev = NULL;
		}
		return (1);
	}
	return (0);
}
