/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:06:58 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/10 16:50:04 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include <libft.h>

typedef struct s_stack
{
	t_dlist	*top;
	t_dlist	*btm;
}				t_stack;

int		stack_swap(t_stack *stack);
int		stack_rotate(t_stack *stack);
int		stack_rotate_reverse(t_stack *stack);
int		stack_push(t_stack *stack_a, t_stack *stack_b);
int		stack_double_swap(t_stack	*stack_a, t_stack *stack_b);
t_dlist	*ft_dlnew(int value);
void	ft_dladdtop(t_dlist **top, t_dlist *node);
void	print_stack(t_stack *stack);

#endif