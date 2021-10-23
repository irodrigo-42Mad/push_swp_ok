/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:53:20 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/23 17:32:59 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

void	push(t_data **my_stack, t_data **dest)
{
	t_data	*aux_nd;

	if (*my_stack)
	{
		aux_nd = (*my_stack)->next;
		(*my_stack)->next = *dest;
		*dest = *my_stack;
		*my_stack = aux_nd;
	}
}

void	push_a(int out, t_data **stk_b, t_data **stk_a)
{
	push(stk_a, stk_b);
	if (out == TRUE)
		write(1, "pa\n", 3);
}

void	push_b(int out, t_data **stk_a, t_data **stk_b)
{
	push(stk_a, stk_b);
	if (out == TRUE)
		write(1, "pb\n", 3);
}
