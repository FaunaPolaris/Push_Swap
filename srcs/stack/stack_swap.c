/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:15:56 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/10 15:41:09 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

int	stack_swap(t_stack *stack)
{
	if (!stack->top)
	{	
		ft_putstr_fd("Error: stack is undefined", 2);
		return (0);
	}
	if (stack->top->next)
	{
		stack->top->value ^= stack->top->next->value;
		stack->top->next->value ^= stack->top->value;
		stack->top->value ^= stack->top->next->value;
		return (1);
	}
	return (0);
}
