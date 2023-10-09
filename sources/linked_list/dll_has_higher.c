/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_has_higher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:46:29 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/09 18:46:34 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

int	dll_has_higher(t_dllist *head, int compare)
{
	t_dllist	*temp;

	if (!head)
		return (0);
	temp = head;
	while (temp)
	{
		if (temp->as_int > compare)
			return (1);
		temp = temp->next;
	}
	return (0);
}
