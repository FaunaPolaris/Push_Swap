/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_has_lower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:43:42 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/09 18:43:43 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

int	dll_has_lower(t_dllist *head, int compare)
{
	t_dllist	*temp;

	if (!head)
		return (0);
	temp = head;
	while (temp)
	{
		if (temp->as_int < compare)
			return (1);
		temp = temp->next;
	}
	return (0);
}
