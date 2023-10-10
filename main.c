/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:29:48 by nprudenc          #+#    #+#             */
/*   Updated: 2023/10/10 17:30:05 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

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