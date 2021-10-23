/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:56:38 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/19 12:36:02 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

void	rev_rot(t_data **stk)
{
	t_data	*ctrl;
	t_data	*last;

	if (*stk)
	{
		last = ft_getlast(*stk);
		ctrl = ft_goto_el(*stk, ft_lstlength(*stk) - 2);
		last->next = *stk;
		*stk = last;
		ctrl->next = NULL;
	}
}

void	rev_rot_a(t_data **stk_a, t_data **stk_b)
{
	(void)stk_b;
	rev_rot(stk_a);
	write (1, "rra\n", 5);
}

void	rev_rot_b(t_data **stk_a, t_data **stk_b)
{
	(void)stk_a;
	rev_rot(stk_b);
	write (1, "rrb\n", 5);
}

void	rev_rot_ab(t_data **stk_a, t_data **stk_b)
{
	rev_rot(stk_a);
	rev_rot(stk_b);
	write (1, "rrr\n", 5);
}
