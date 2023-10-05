/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:37:31 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/05 16:48:01 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

int	reverse_rotate(t_stack *stack)
{
	if (!stack->back)
	{
		ft_putstr_fd("Error: undefined stack back!", 2);
		return (0);
	}
	if (stack->front)
	{
		if (stack->front == stack->back)
			stack_swap(stack);
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
	return (0);
}