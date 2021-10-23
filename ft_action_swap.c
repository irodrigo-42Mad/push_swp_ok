/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:53:30 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/23 17:48:56 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

void	swap(t_data **my_stack)
{
	t_data	*aux;

	if (*my_stack)
	{
		aux = (*my_stack)->next;
		(*my_stack)->next = aux->next;
		aux->next = *my_stack;
		*my_stack = aux;
	}
}

void	swap_a(int out, t_data **stk_a, t_data **stk_b)
{
	(void)stk_b;
	swap(stk_a);
	if (out == TRUE)
		write (1, "sa\n", 3);
}

void	swap_b(int out, t_data **stk_a, t_data **stk_b)
{
	(void)stk_a;
	swap(stk_b);
	if (out == TRUE)
		write (1, "sb\n", 3);
}

void	swap_ab(int out, t_data **stk_a, t_data **stk_b)
{
	swap(stk_a);
	swap(stk_b);
	if (out == TRUE)
		write (1, "ss\n", 3);
}
