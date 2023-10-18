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
static int 	st_error(t_stack *stack_a);
static void	st_find_best_sort(t_stack *stack_a, t_stack *stack_b);
static void	st_find_dindex(t_dllist *head);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (st_error(NULL));
	if (!st_validate(&stack_a, argv))
		return (st_error(stack_a));
	stack_b = stck_new(NULL, 'b');
	if (!stack_b)
		return (st_error(stack_a));
	st_find_dindex(stack_a->front);
	st_find_best_sort(stack_a, stack_b);
	stck_rmv(stack_a);
	stck_rmv(stack_b);
	return (0);
}

static void	st_find_dindex(t_dllist *head)
{
	int		size;
	int		i;
	int		current;

	i = -1;
	size = dll_size(head);
	current = dll_lowest(head);
	while (++i < size)
	{
		dll_pointer(head, current)->dindex = i;
		current  = dll_closest_higher(head, current);
	}
}

static void	st_find_best_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_size;

	stack_size = dll_size(stack_a->front);
	if (stack_size == 2)
		sort_2(stack_a);
	else if (stack_size == 3)
		sort_3(stack_a);
	else if (stack_size == 4)
		sort_4(stack_a, stack_b);
	else if (stack_size == 5)
		sort_5(stack_a, stack_b);
	else
	{
		if (stack_size >= 500)
			sort_v2(stack_a, stack_b,
					dll_lowest(stack_a->front), 50, 0);
		else
			sort_v2(stack_a, stack_b,
					dll_lowest(stack_a->front), 20, 0);
		stck_highest_to_front(stack_b);
		stck_push_all(stack_b, stack_a);
	}
}

static int	st_validate(t_stack **stack_a, char **args)
{
	int	i;

	*stack_a = stck_new(NULL, 'a');
	if (!*stack_a)
		return (0);
	(*stack_a)->front = dll_new_node(args[1]);
	if (!(*stack_a)->front)
		return (0);
	i = 1;
	while (args[++i])
	{
		if (fp_strcmp("", args[i]) == 0 || !fp_strisnb(args[i])
				|| !dll_add_back((*stack_a)->front, args[i]))
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
	(*stack_a)->back = dll_fnd_back((*stack_a)->front);
	return (1);
}

static int 	st_error(t_stack *stack_a)
{
	if (stack_a)
		stck_rmv(stack_a);
	fp_putendl_fd("Error", 2);
	return (1);
}
