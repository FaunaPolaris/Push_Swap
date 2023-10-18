/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:35:23 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/10 17:46:57 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include "llist.h"

typedef struct s_stack
{
	char		id;
	int		dindex;
	t_dllist	*front;
	t_dllist	*back;
}	t_stack;

// stack allocation and dealocation

t_stack	*stck_new(void **values, char id);
void	stck_rmv(t_stack *stack);

// single stack movements

int	stck_swap(t_stack *stack, int print);
int	stck_push(t_stack *donor, t_stack *receiver);
int	stck_rott_rgt(t_stack *stack, int print);
int	stck_rott_lft(t_stack *stack, int print);

// double stack movements

int	stck_swap_double(t_stack *stack_a, t_stack *stack_b);
int	stck_rott_rgt_double(t_stack *stack_a, t_stack *stack_b);
int	stck_rott_lft_double(t_stack *stack_a, t_stack *stack_b);

// entire stack movements

int	stck_push_all(t_stack *from, t_stack *to);
int	stck_lowest_to_front(t_stack *stack);
int	stck_highest_to_front(t_stack *stack);

// limit stack movements

int	stck_push_higher(int than,t_stack *from, t_stack *to);
int	stck_push_lower(int than, t_stack *from, t_stack *to);

// stack visualization

void	stck_disp(t_stack *stack);

#endif
