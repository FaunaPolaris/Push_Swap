/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_new_rlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:45:20 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/09 17:52:39 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

t_dllist	*dll_new_rlist(void **values)
{
	int		i;
	t_dllist	*head;

	i = 0;
	if (!values || !values[0])
		return (NULL);
	head = (t_dllist *)fp_calloc(1, sizeof(t_dllist));
	if (!head)
		return (NULL);
	head->as_int = fp_atoi((char *)values[0]);
	while (values[++i])
	{
		if (!dll_add_frnt(&head, values[i]))
		{
			dll_clear(&head);
			return (NULL);
		}
	}
	return (head);
}
