/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_rmv_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:55:42 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/04 14:55:44 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

void	dll_clear(t_dllist **head)
{
	t_dllist	*old;

	if (!head[0])
		return ;
	while (head[0]->next)
	{
		old = head[0];
		head[0] = head[0]->next;
		free(old);
	}
	free(head[0]);
	head[0] = NULL;
}
