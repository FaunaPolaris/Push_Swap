/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:21:01 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/13 14:21:08 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static int	st_validate(t_stack **stack_a, char **args);
static int 	st_error(t_stack *stack_a, int id);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (st_error(NULL, 1));
	if (!st_validate(&stack_a, argv))
		return (st_error(stack_a, 2));
	stack_b = stck_new(NULL, 'b');
	if (!stack_b)
		return (st_error(stack_a, 3));
	stck_disp(stack_a);
	stck_rmv(stack_a);
	stck_rmv(stack_b);
	return (0);
}

static int	st_validate(t_stack **stack_a, char **args)
{
	int	i;

	*stack_a = stck_new(NULL, 'a');
	if (!*stack_a)
		return (0);
	(*stack_a)->front = dll_new_node(args[1], 0);
	if (!(*stack_a)->front)
		return (0);
	i = 1;
	while (args[++i])
	{
		if (fp_strcmp("", args[i]) == 0 || !fp_strisnb(args[i])
				|| !dll_add_back((*stack_a)->front, args[i], 0))
		{
			dll_clear(&(*stack_a)->front);
			return (0);
		}
	}
	if (dll_is_crescent((*stack_a)->front)
			|| dll_has_duplicates((*stack_a)->front))
	{
		dll_clear(&(*stack_a)->front);
		return (0);
	}
	return (1);
}

static int 	st_error(t_stack *stack_a, int id)
{
	if (stack_a)
		stck_rmv(stack_a);
	fp_putendl_fd("Error", 2);
	fp_putnbr_fd(id, 1);
	return (1);
}
