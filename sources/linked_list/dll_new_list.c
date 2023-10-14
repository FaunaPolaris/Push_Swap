/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_new_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:07:05 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/04 15:07:06 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

t_dllist	*dll_new_list(void **values)
{
	int		i;
	t_dllist	*head;

	i = 0;
	if (!values || !values[0] || *(char *)values[0] == '\0')
		return (NULL);
	head = (t_dllist *)fp_calloc(1, sizeof(t_dllist));
	if (!head)
		return (NULL);
	head->as_int = fp_atoi((char *)values[0]);
	while (values[++i])
	{
		if (!dll_add_back(head, values[i]))
		{
			dll_clear(&head);
			return (NULL);
		}
	}
	return (head);
}
