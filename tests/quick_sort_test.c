/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:47:05 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/10 16:29:19 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

t_stack	*stack_a;
t_stack *stack_b;
void	**as_voids_a;

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (1);
	as_voids_a = (void **)fp_split(argv[1], ' ');
	if (!as_voids_a)
		return (1);
	stack_a = stck_new(as_voids_a, 'a');
	stack_b = stck_new(NULL, 'b');
	int	highest = dll_highest(stack_a->front);
	for (i = 0; highest > 0; highest /= 10)
		i++;
//	stck_disp(stack_a);
	sort_by_base(stack_a, stack_b, 10);
	sort_by_base(stack_a, stack_b, 10);
	stck_push_all(stack_b, stack_a);
//	stck_disp(stack_a);
	return (0);
}
