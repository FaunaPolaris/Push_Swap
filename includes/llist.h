/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:05:28 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/10 18:05:26 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLIST_H
#define LLIST_H

#include "libft.h"

typedef struct s_dllist
{
	struct s_dllist	*next;
	struct s_dllist	*prev;
	int		as_int;
}	t_dllist;

// doubly linked list creation and deletion

t_dllist	*dll_new_node(void *value);
t_dllist	*dll_new_list(void **values);
t_dllist	*dll_new_rlist(void **values);
void		dll_clear(t_dllist **head);

int		dll_add_back(t_dllist *head, void *value);
int		dll_add_frnt(t_dllist **head, void *value);

// doubly linked list utilities

int		dll_has(t_dllist *head, int find);
int		dll_has_lower(t_dllist *head, int compare);
int		dll_has_higher(t_dllist *head, int compare);
int		dll_has_duplicates(t_dllist *head);

int		dll_next_lower(t_dllist *head, int than);
int		dll_next_lower_front(t_dllist *head, int than);
int		dll_next_higher(t_dllist *head, int than);

int		dll_highest(t_dllist *head);
int		dll_lowest(t_dllist *head);
int		dll_mediam(t_dllist *head);

int		dll_is_crescent(t_dllist *head);

int		dll_size(t_dllist *head);
int		dll_index(t_dllist *head, int of);
int		dll_rindex(t_dllist *head, int of);
int		dll_poistion(t_dllist *head, int of);

t_dllist	*dll_fnd_back(t_dllist *head);

// list visualization

void		dll_putlist(t_dllist *head, int fd);

#endif
