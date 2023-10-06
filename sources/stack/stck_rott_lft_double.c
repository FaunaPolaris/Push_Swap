/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_rott_lft_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:26:28 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/06 17:26:30 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stck_rott_lft_double(t_stack stack_a, t_stack stack_b)
{
	stck_rott_lft(stack_a);
	stck_rott_lft(stack_b);
	return (1);
}
