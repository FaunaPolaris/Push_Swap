/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:33:20 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/10 17:30:48 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
#define SORTING_H

#include "stack.h"

void	sort_quick(t_stack *stack_a, t_stack *stack_b);
void	sort_from_lower(t_stack *stack_a, t_stack *stack_b);

#endif
