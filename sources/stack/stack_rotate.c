/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:56:05 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/06 18:54:33 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

int	stack_rotate(t_stack *stack)
{
	if (!stack->back)
	{
		ft_putstr_fd("Error: stack back is undefined!", 2);
		return (0);
	}
	if (stack->front)
	{	
		if (stack->front->next == stack->back)
			swap_stack(stack);
		else
		{
			stack->back->next = stack->front;
			stack->front->prev = stack->back;
			stack->front = stack->back;
			stack->front->prev->next = NULL;
			stack->back = stack->back->prev;
			stack->front->prev = NULL;
		}
		return (1);
	}
	return (0);
}
