/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:05:28 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/09 18:38:58 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLIST_H
#define LLIST_H

#include "libft.h"

typedef struct s_dllist
{
	struct s_dllist	*next;
	struct s_dllist	*prev;
	void		*as_void;
	int		as_int;
	char		*as_str;
}	t_dllist;

t_dllist	*dll_new_node(void *value);
t_dllist	*dll_new_list(void **values);
t_dllist	*dll_new_rlist(void **values);
void		dll_clear(t_dllist **head);

int		dll_add_back(t_dllist *head, void *value);
int		dll_add_frnt(t_dllist **head, void *value);
int		dll_size(t_dllist *head);

int		dll_has(t_dllist *head, int find);
int		dll_has_lower(t_dllist *head, int compare);
int		dll_has_higher(t_dllist *head, int compare);

t_dllist	*dll_fnd_back(t_dllist *head);

void		dll_putlist(t_dllist *head, char content_type, int fd);

#endif
