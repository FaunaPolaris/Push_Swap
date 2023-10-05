/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:52:54 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/14 23:16:48 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atox(char *hex)
{
	int		i;
	int		j;
	int		nbr;

	if (!hex)
		return (0xffffff);
	i = ft_strlen(hex) - 3;
	j = 2;
	nbr = 0;
	while (hex[j])
	{
		if (ft_isdigit(hex[j]))
			nbr += (hex[j] - 48) * pow(16, i--);
		if (hex[j] >= 97 && hex[j] <= 102)
			nbr += (hex[j] - 97) * pow(16, i--);
		if (hex[j] >= 65 && hex[j] <= 70)
			nbr += (hex[j] - 65) * pow(16, i--);
		j++;
	}
	return (nbr);
}
