/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:27:50 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/06 13:27:52 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stck_push(t_stack *donor, t_stack *receiver)
{
	t_dllist	*donated;

	if (!donor->front)
		return (0);
	fp_printf("p%c\n", receiver->id);
	donated = donor->front;
	if (donor->front->next)
	{
		donor->front = donor->front->next;
		donor->front->prev = NULL;
	}
	else
		donor->front = NULL;
	if (!receiver->front)
	{
		receiver->front = donated;
		donated->next = NULL;
	}
	else
	{
		receiver->front->prev = donated;
		donated->next = receiver->front;
		receiver->front = donated;
	}
	return (1);
}
