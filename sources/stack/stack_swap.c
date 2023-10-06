/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:15:56 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/06 18:54:39 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

int	swap_stack(t_stack *stack)
{
	if (!stack->front)
	{	
		ft_putstr("Error: stack is undefined", 2);
		return (0);
	}
	if (stack->front->next)
	{
		stack->front->content ^= stack->front->next->content;
		stack->front->next->content ^= stack->front->content;
		stack->front->content ^= stack->front->next->content;
		return (1);
	}
	return (0);
}
