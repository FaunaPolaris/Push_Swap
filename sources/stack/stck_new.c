/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:33:22 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/06 11:33:23 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stck_new(void **values, char id)
{
	t_dllist	*list;
	t_stack		*output;

	output = (t_stack *)fp_calloc(1, sizeof(t_stack));
	if (!output)
		return (NULL);
	list = dll_new_list(values);
	output->id = id;
	output->front = list;
	if (list && list->next)
		output->back = dll_fnd_back(list);
	else
		output->back = NULL;
	return (output);
}

void	stck_rmv(t_stack *stack)
{
	dll_clear(&stack->front);
	free(stack);
}
