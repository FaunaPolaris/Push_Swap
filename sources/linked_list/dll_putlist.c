/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_putlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:26:27 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/04 15:26:28 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

void	dll_putlist(t_dllist *head, int fd)
{
	if (!head)
		return ;
	while (head)
	{
		fp_putnbr_fd(head->as_int, fd);
		if (head->next)
			write(fd, " <- -> ", 7);
		head = head->next;
	}
	write(fd, "\n", 1);
}
