/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:16:54 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/29 17:16:29 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_select_char(char c, va_list list)
{		
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar(va_arg(list, int));
	else if (c == '%')
		counter += ft_putchar('%');
	else if (c == 's')
		counter += ft_printstr(va_arg(list, char *));
	else if (c == 'i' || c == 'd')
		counter += ft_putnbr(va_arg(list, int));
	else if (c == 'u')
		counter += ft_print_long(va_arg(list, int));
	else if (c == 'x')
		counter += ft_print_hex(va_arg(list, unsigned int), 'x');
	else if (c == 'X')
		counter += ft_print_hex(va_arg(list, unsigned int), 'X');
	else if (c == 'p')
		counter += ft_print_ptr(va_arg(list, unsigned long));
	return (counter);
}

int	ft_printf(const char *str, ...)
{	
	va_list	list;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(list, str);
	while (str[i])
	{	
		if (str[i] == '%')
			counter += ft_select_char(str[++i], list);
		else
			counter += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (counter);
}
