/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:06:58 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/07 18:36:52 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACHS_H

# include <libft.h>

typedef struct s_stack
{
	t_dlist	*top;
	t_dlist	*btm;
}				t_stack;

int	stack_swap(t_stack *stack);
int	stack_rotate(t_stack *stack);
int	stack_rotate_reverse(t_stack *stack);
int	stack_push(t_stack *stack_a, t_stack *stack_b);
int	stack_double_swap(t_stack	*stack_a, t_stack *stack_b);

#endif