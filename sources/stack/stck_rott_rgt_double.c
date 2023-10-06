/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_rott_rgt_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:28:13 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/06 17:28:14 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stck_rott_rgt_double(t_stack *stack_a, t_stack *stack_b)
{
	stck_rott_rgt(stack_a);
	stck_rott_lft(stack_b);
	return (1);
}
