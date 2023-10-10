/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:37:31 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/07 18:37:46 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

int	stack_rotate_reverse(t_stack *stack)
{
	if (!stack->btm)
	{
		ft_putstr_fd("Error: undefined stack btm!", 2);
		return (0);
	}
	if (stack->top)
	{
		if (stack->top == stack->btm)
			stack_swap(stack);
		else
		{
			stack->top->prev = stack->btm;
			stack->btm->next = stack->top;
			stack->top = stack->top->next;
			stack->top->prev = NULL;
			stack->btm = stack->btm->next;
			stack->btm->next = NULL;
		}
		return (1);
	}
	return (0);
}
