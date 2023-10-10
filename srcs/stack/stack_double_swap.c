/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_double_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:29:34 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/07 18:37:01 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>
#include <libft.h>

int	stack_double_swap(t_stack	*stack_a, t_stack *stack_b)
{
	if (!stack_a->top || !stack_b->top)
	{
		ft_putstr_fd("Error: stack_a or stack_b is undefined!", 2);
		return (0);
	}
	else if (stack_a->top && stack_b->top)
	{
		swap_stack(stack_a);
		swap_stack(stack_b);
	}
	return (1);
}
