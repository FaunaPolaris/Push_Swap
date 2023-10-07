/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:41:59 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/07 18:37:30 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

int	stack_push(t_stack *stack_a, t_stack *stack_b)
{
	t_dlist	*stack_at;
	t_dlist	*stack_bt;

	if (!stack_a || !stack_b)
	{
		ft_putstr_fd("Error: stack_a or stack_b is undefined!", 2);
		return (0);
	}
	if (stack_b->top->next)
		stack_bt = stack_b->top->next;
	else
		stack_bt = NULL;
	stack_at = stack_a->top;
	stack_at->prev = stack_b->top;
	stack_a->top = stack_b->top;
	stack_a->top->next = stack_at;
	stack_b->top = stack_bt;
	stack_bt->prev = NULL;
}
