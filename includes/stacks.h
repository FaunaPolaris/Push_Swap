/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:06:58 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/04 18:36:16 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACHS_H

# include <libft.h>

typedef struct s_stack
{
	t_list	*front;
	t_list	*back
}				t_stack;

int	swap_stack(t_stack *stack);

#endif