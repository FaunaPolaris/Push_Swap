/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:41:59 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/10 17:01:21 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include <stdio.h>

int	stack_push_ab(t_stack *stack_a, t_stack *stack_b)
{
	t_dlist	*a_top;

	if (!stack_a || !stack_a->top || !stack_b)
	{
		ft_putstr_fd("Error: stack_a is undefined!\n", 2);
		return (0);
	}
	if (stack_a->top->next)
	{
		a_top = stack_a->top->next;
		a_top->prev = NULL;
	}
	else
		a_top = NULL;
	if (!stack_b->top)
	{
		stack_b->top = stack_a->top;
		stack_b->btm = stack_a->top;
		stack_a->top = a_top;
		stack_b->top->prev = NULL;
		stack_b->top->next = NULL;
	}
	else
	{
		stack_b->top->prev = stack_a->top;
		stack_a->top->next = stack_b->top;
		stack_b->top = stack_a->top;
		stack_a->top = a_top;
	}
	return (1);
}

int main(void)
{
	t_stack *stck_a = ft_calloc(1, sizeof(t_stack));
	t_stack *stck_b = ft_calloc(1, sizeof(t_stack));
	int	i = -1;
	stck_b->top = NULL;
	stck_b->btm = NULL;
	stck_a->top = ft_calloc(1, sizeof(t_dlist));
	stck_a->btm = ft_calloc(1, sizeof(t_dlist));
	while (++i < 5)
		ft_dladdtop(&stck_a->top,ft_dlnew(i));
	ft_printf("stack_a:\n");
	print_stack(stck_a);
	stack_push_ab(stck_a, stck_b);
	stack_push_ab(stck_a, stck_b);
	stack_push_ab(stck_a, stck_b);
	stack_push_ab(stck_a, stck_b);
	ft_printf("stack_b:\n");
	print_stack(stck_b);
	ft_printf("stack_a:\n");
	print_stack(stck_a);
	i = -1;
	
	return (0);
}
