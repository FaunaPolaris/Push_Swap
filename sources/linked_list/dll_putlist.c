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
}

static void	st_print_as_char(t_dllist *head, int fd)
{
	while (head->next)
	{
		fp_putchar_fd(*(char *)head->value, fd);
		write(fd, "\n", 1);
		head = head->next;
	}
	fp_putchar_fd(*(char *)head->value, fd);
	write(fd, "\n", 1);
}

static void	st_print_as_string(t_dllist *head, int fd)
{
	while (head->next)
	{
		fp_putstr_fd((char *)head->value, fd);
		write(fd, "\n", 1);
		head = head->next;
	}
	fp_putstr_fd((char *)head->value, fd);
	write(fd, "\n", 1);
}

static void	st_print_as_int(t_dllist *head, int fd)
{
	while (head->next)
	{
		fp_putnbr_fd(fp_atoi((char *)head->value), fd);
		write(fd, "\n", 1);
		head = head->next;
	}
	fp_putnbr_fd(fp_atoi((char *)head->value), fd);
	write(fd, "\n", 1);
}
