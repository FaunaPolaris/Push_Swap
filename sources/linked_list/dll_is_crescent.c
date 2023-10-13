/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_is_crescent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:13:29 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/13 15:13:31 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

int	dll_is_crescent(t_dllist *head)
{
	t_dllist	*temp;

	temp = head;
	while (temp)
	{
		if (temp->next && temp->as_int > temp->next->as_int)
			return (0);
		temp = temp->next;
	}
	return (1);
}
