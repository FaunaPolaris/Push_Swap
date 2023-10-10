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

static void	st_print_as_char(t_dllist *head, int fd);
static void	st_print_as_string(t_dllist *head, int fd);
static void	st_print_as_int(t_dllist *head, int fd);

void	dll_putlist(t_dllist *head, char value_type, int fd)
{
	if (!head)
		return ;
	if (value_type == 'c')
		st_print_as_char(head, fd);
	else if (value_type == 's')
		st_print_as_string(head, fd);
	else if (value_type == 'i')
		st_print_as_int(head, fd);
	else
		fp_printf("Error: unrecognizable value type of :'%c'\n",
				value_type);
	write(1, "\n", 1);
}

static void	st_print_as_char(t_dllist *head, int fd)
{
	while (head)
	{
		fp_putchar_fd(*(char *)head->as_void, fd);
		if (head->next)
			write(fd, " <- -> ", 7);
		head = head->next;
	}
	write(fd, "\n", 1);
}

static void	st_print_as_string(t_dllist *head, int fd)
{
	while (head)
	{
		fp_putstr_fd(head->as_str, fd);
		if (head->next)
			write(fd, " <- -> ",7);
		head = head->next;
	}
	write(fd, "\n", 1);
}

static void	st_print_as_int(t_dllist *head, int fd)
{
	while (head)
	{
		fp_putnbr_fd(fp_atoi((char *)head->as_void), fd);
		if (head->next)
			write(fd, " <- -> ", 7);
		head = head->next;
	}
	write(fd, "\n", 1);
}
