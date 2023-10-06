/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_double_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:29:34 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/06 18:54:27 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>
#include <libft.h>

int	stack_double_swap(t_stack	*stack_a, t_stack *stack_b)
{
	if (!stack_a->front || !stack_b->front)
	{
		ft_putstr_fd("Error: stack_a or stack_b is undefined!", 2);
		return (0);
	}
	else if (stack_a->front && stack_b->front)
	{
		swap_stack(stack_a);
		swap_stack(stack_b);
	}
	return (1);
}
