/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_has.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:37:16 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/09 18:40:47 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

int	dll_has(t_dllist *head, int find)
{
	t_dllist	*temp;

	if (!head)
		return (0);
	temp = head;
	while (temp)
	{
		if (temp->as_int == find)
			return (1);
		temp = temp->next;
	}
	return (0);
}
