/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_swap_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:23:34 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/06 17:23:34 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stck_swap_double(t_stack *stack_a, t_stack stack_b)
{
	stck_swap(stack_a);
	stck_swap(stack_b);
	return (1);
}
