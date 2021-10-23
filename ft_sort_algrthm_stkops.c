/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algrthm_stkops.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:24:42 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/19 12:48:47 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

// si no funciona habrá que mantener la antigua forma de contar los elementos
t_data	*ft_stack_split(t_data **stk, int len)
{
	t_data	*aux;

	aux = NULL;
	len++;
	while (--len)
		push_b(stk, &aux);
	return (aux);
}

void	ft_remv_elm_a(t_data **stk_a, t_data **stk_b, int *a_len)
{
	rotate_a(stk_a, stk_b);
	*a_len -= 1;
}

void	ft_remv_elm_b(t_data **stk_a, t_data **stk_b)
{
	push_a(stk_a, stk_b);
	rotate_a(stk_a, stk_b);
}

short	ft_order_two(t_data **stk_a, t_data **stk_b)
{
	if (!(*stk_a)->next && !(*stk_b)->next)
	{
		if ((*stk_a)->val < (*stk_b)->val)
			ft_remv_elm_b(stk_a, stk_b);
		else
			push_a(stk_a, stk_b);
		return (TRUE);
	}
	return (FALSE);
}
