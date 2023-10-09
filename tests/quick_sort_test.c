/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:47:05 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/09 17:55:02 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

t_stack	*stack_a;
t_stack *stack_b;
void	**as_voids_a;

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	as_voids_a = (void **)fp_split(argv[1], ' ');
	if (!as_voids_a)
		return (1);
	stack_a = stck_new(as_voids_a, 'a');
	stack_b = stck_new(NULL, 'b');
	stck_disp(stack_a);
	stck_disp(stack_b);
	sort_quick(stack_a, stack_b);
	return (0);
}
