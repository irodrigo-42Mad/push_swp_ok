/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_swp_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:30:52 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/22 13:17:16 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

// hay que juntar estas dos funciones en una sola
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
		swap_a(a, b/*, 1*/);
	else if ((*a)->pos == 2 && next->pos)
	{
		swap_a(a, b/*, 1*/);
		rev_rot_a(a, b/*, 1*/);
	}
	else if ((*a)->pos == 2 && !next->pos)
		rotate_a(a, b/*, 1*/);
	else if (!(*a)->pos && next->pos == 2)
	{
		swap_a(a, b /*,1*/);
		rotate_a(a, b/*, 1*/);
	}
	else
		rev_rot_a(a, b/*, 1*/);
}
