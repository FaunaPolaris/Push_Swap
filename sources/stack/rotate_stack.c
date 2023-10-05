/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:56:05 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/05 16:48:19 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

int	rotate_stack(t_stack *stack)
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