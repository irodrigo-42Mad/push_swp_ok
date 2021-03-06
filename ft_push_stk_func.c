/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stk_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:38:38 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/23 20:51:14 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

void	ft_a_split(int n_elm, t_data **a, t_data **b)
{
	t_data	*pivot;
	int		is_limit_set;

	if (!(*b)->next)
	{
		push_a(TRUE, a, b);
		return ;
	}
	pivot = ft_get_axis(n_elm, b);
	is_limit_set = 0;
	while ((*b) && ft_exist_left_val(*b, pivot))
	{
		if ((*b)->val > pivot->val)
		{
			ft_set_sgimit(b, &is_limit_set);
			push_a(TRUE, a, b);
		}
		else
		{
			if ((*b)->pos == 0 || (*b)->pos == ft_getlast(*a)->pos + 1)
				ft_remv_elm_b(TRUE, a, b);
			else
				rotate_b(TRUE, a, b);
		}
	}
}

void	ft_b_split(int n_elm, t_data **a, t_data **b)
{
	int		stk_len;
	int		rot;
	t_data	*axis;
	t_data	*limit;

	rot = 0;
	stk_len = ft_lstlength(*a);
	axis = ft_get_axis(n_elm, a);
	limit = NULL;
	while (ft_lstlength(*b) <= n_elm / 2)
	{
		if ((*a)->seg_lim)
			limit = (*a)->next;
		if ((*a)->val <= axis->val)
			push_b(TRUE, a, b);
		else
		{
			if (n_elm < stk_len)
				rot++;
			rotate_a(TRUE, a, b);
		}
	}
	ft_stk_rotate_bk(rot, a, b);
	ft_new_sglimit(*a, limit);
}

void	ft_tiny_b_split(int n_elm, t_data **a, t_data **b)
{
	short	limit;

	if (n_elm == 4)
		limit = 1;
	else
		limit = 2;
	while (ft_lstlength(*b) < limit)
	{
		if ((*a)->pos > 2)
			push_b(TRUE, a, b);
		else
			rotate_a(TRUE, a, b);
	}
	if ((*b)->next && (*b)->val > ((t_data *)(*b)->next)->val)
		rotate_b(TRUE, a, b);
}

void	ft_rev_split(int n_elm, t_data **a, t_data **b)
{
	if (n_elm > 20)
	{
		ft_a_split(n_elm, a, b);
		ft_rev_split(ft_lstlength(*b), a, b);
	}
	else if (n_elm)
	{
		ft_restore_back(n_elm, a, b);
		ft_max_axisrot(a, b);
	}
}

//sorted = sort_part_stack(*stk, n_elm);
t_data	*ft_get_axis(int n_elm, t_data **stk)
{
	t_data	*sorted;
	t_data	*axis;

	sorted = ft_stack_pop(*stk, n_elm);
	sorted = ft_merge_sort(sorted);
	axis = ft_goto_el(sorted, n_elm / 2);
	return (axis);
}
