/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dladdtop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:13:59 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/10 16:20:58 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dladdtop(t_dlist **top, t_dlist *node)
{
	if (!node)
		return ;
	if (*top)
	{
		(*top)->prev = node;
		node->next = *top;
		*top = node;
	}
	else
		*top = node;
}