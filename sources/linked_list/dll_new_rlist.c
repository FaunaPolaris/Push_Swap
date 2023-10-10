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

static int	st_find_padding(char **values)
{
	int	i;
	int	g_len;
	int	s_len;
	int	output;

	i = -1;
	output = 0;
	g_len = fp_grdlen(values);
	while (++i < g_len)
	{
		s_len = fp_strlen(values[i]);
		if (s_len > output)
			output = s_len;
	}
	return (output);
}

t_dllist	*dll_new_rlist(void **values)
{
	int		i;
	int		padding;
	t_dllist	*head;

	i = 0;
	if (!values || !values[0])
		return (NULL);
	head = (t_dllist *)fp_calloc(1, sizeof(t_dllist));
	if (!head)
		return (NULL);
	padding = st_find_padding((char **)values);
	head->as_void = values[0];
	head->as_int = fp_atoi((char *)values[0]);
	head->as_str = fp_strpadding((char *)values[0], padding);
	while (values[++i])
	{
		if (!dll_add_frnt(&head, values[i], padding))
		{
			dll_clear(&head);
			return (NULL);
		}
	}
	return (head);
}
