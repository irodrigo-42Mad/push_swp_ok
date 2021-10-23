/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stk_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:57:43 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/23 10:40:03 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

void	ft_rot_axis_max(int n_elm, t_data **a,
								t_data **b, t_data *max)
{
	int		d;
	t_data	*aux;

	d = 0;
	aux = *b;
	while (aux && aux->val != max->val)
	{
		aux = aux->next;
		d++;
	}
	if (d < n_elm / 2)
		rotate_b(a, b/*, 1*/);
	else
		rev_rot_b(a, b/*, 1*/);
}

void	ft_split_rot_b(int n_elm, t_data **a, t_data **b)
{
	while (n_elm)
	{
		if ((*a)->pos == 0 || (*a)->pos == ft_getlast(*a)->pos + 1)
			rotate_a(a, b/*, 1*/);
		else
			push_b(a, b/*, 1*/);
		n_elm--;
	}
}

void	ft_stk_rotate_bk(int rot_el, t_data **a, t_data **b)
{
	while (rot_el)
	{
		if (ft_min_max(*b))
			rev_rot_a(a, b/*, 1*/);
		else
			rev_rot_ab(a, b/*, 1*/);
		rot_el--;
	}
}

void	ft_max_axisrot(t_data **a, t_data **b)
{
	while ((*a)->next && (*a)->pos == ft_getlast(*a)->pos + 1)
		rotate_a(a, b/*, 1*/);
}

void	ft_restore_back(int n_elm, t_data **a, t_data **b)
{
	t_data	*sort;
	t_data	*max;

	//sorted = sort_part_stack(*b, n_elm);
	sort = ft_stack_pop(*b, n_elm);
	sort = ft_merge_sort(sort);
	while (n_elm)
	{
		// por aqui andurio....
		max = ft_getlast(sort);
		if ((*b)->pos == 0 || (*b)->pos == ft_getlast(*a)->pos + 1)
		{
			push_a(a, b/*, 1*/);
			rotate_a(a, b/*, 1*/);
			n_elm--;
		}
		else if ((*b)->val == max->val)
		{
			push_a(a, b/*, 1*/);
			ft_goto_el(sort, ft_lstlength(sort) - 2)->next = NULL;
			n_elm--;
		}
		else
			ft_rot_axis_max(n_elm, a, b, max);
	}
}
