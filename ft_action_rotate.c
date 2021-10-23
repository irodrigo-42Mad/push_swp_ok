/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:14:07 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/19 12:27:06 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

void	rotate(t_data **stk)
{
	t_data	*aux;
	t_data	*last;

	if (*stk && (*stk)->next)
	{
		aux = (*stk)->next;
		last = ft_getlast(*stk);
		last->next = *stk;
		(*stk)->next = NULL;
		*stk = aux;
	}
}

void	rotate_a(t_data **stk_a, t_data **stk_b)
{
	(void)stk_b;
	rotate(stk_a);
	write (1, "ra\n", 3);
}

void	rotate_b(t_data **stk_a, t_data **stk_b)
{
	(void)stk_a;
	rotate(stk_b);
	write (1, "rb\n", 3);
}

void	rotate_ab(t_data **stk_a, t_data **stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
	write (1, "rr\n", 3);
}
