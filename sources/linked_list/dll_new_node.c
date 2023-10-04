/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:16:22 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/04 14:16:23 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

t_dllist	*dll_new_node(void *value)
{
	t_dllist	*output;

	output = (t_dllist *)fp_calloc(1, sizeof(t_dllist));
	if (!output)
		return (NULL);
	output->value = value;
	output->next = NULL;
	output->prev = NULL;
	return (output);
}
