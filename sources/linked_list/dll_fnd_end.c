/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_fnd_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:24:19 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/04 15:24:20 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

t_dllist	*dll_fnd_back(t_dllist *head)
{
	t_dllist	*back;

	back = head;
	while (back->next)
		back = back->next;
	return (back);
}
