/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:41:59 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/04 19:39:26 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

int	stack_push(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*stack_af;
	t_list	*stack_bf;
	
	if (!stack_a || !stack_b)
	{
		ft_putstr_fd("Error: stack_a or stack_b is undefined!", 2);
		return (0);
	}
	if (stack_b->front->next)
		stack_bf = stack_b->front->next;
	else
		stack_bf = NULL;
	stack_af = stack_a->front;	
	stack_af->prev = stack_b->front;	
	stack_a->front = stack_b->front;
	stack_a->front->next = stack_af;
	stack_b->front = stack_bf;
	stack_bf->prev = NULL; 
}