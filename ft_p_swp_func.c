/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_swp_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:30:52 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/23 18:14:27 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

void	ft_push_swap_lite(t_data **a, t_data **b, int len)
{
	if (len <= 3)
		ft_sort_three(a, b);
	else
	{
		ft_tiny_b_split(len, a, b);
		ft_sort_three(a, b);
		ft_rev_split(ft_lstlength(*b), a, b);
	}
}

void	ft_push_swap_lng(t_data **a, t_data **b, int len)
{
	if (len > 20)
		ft_b_split(len, a, b);
	else
		ft_split_rot_b(len, a, b);
	ft_rev_split(ft_lstlength(*b), a, b);
	if ((*a)->pos)
		ft_push_swap_lng(a, b, ft_segment_len(*a));
}

void	ft_sort_three(t_data **a, t_data **b)
{
	t_data	*next;

	next = (*a)->next;
	if (ft_has_sorted(*a, 3, ACTIVE))
		return ;
	if ((*a)->pos == 1 && !next->pos)
		swap_a(TRUE, a, b);
	else if ((*a)->pos == 2 && next->pos)
	{
		swap_a(TRUE, a, b);
		rev_rot_a(TRUE, a, b);
	}
	else if ((*a)->pos == 2 && !next->pos)
		rotate_a(TRUE, a, b);
	else if (!(*a)->pos && next->pos == 2)
	{
		swap_a(TRUE, a, b);
		rotate_a(TRUE, a, b);
	}
	else
		rev_rot_a(TRUE, a, b);
}
