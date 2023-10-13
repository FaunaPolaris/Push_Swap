/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_has_duplicates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:09:14 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/13 15:09:15 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

int	dll_has_duplicates(t_dllist *head)
{
	t_dllist	*position;
	t_dllist	*compare;

	position = head;
	while (position)
	{
		compare = position->next;
		while (compare)
		{
			if (position->as_int == compare->as_int)
				return (1);
			compare = compare->next;
		}
		position = position->next;
	}
	return (0);
}
