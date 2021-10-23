/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_srt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:05:31 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/23 11:59:35 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

void	ft_prn_stat(int state)
{
	if (state == 1)
		write (1, "KO\n", 4);
	else
		write (1, "OK\n", 4);
}

void	checker(t_data *stk_a, t_data *stk_b)
{
	int	aux;

	if (stk_b)
	{
		ft_prn_stat(1);
		exit(0);
	}
	aux = stk_a->val;
	while (stk_a->next)
	{
		stk_a = stk_a->next;
		if (aux >= stk_a->val)
		{
			ft_prn_stat(1);
			exit(0);
		}
	}
	ft_prn_stat(2);
}

void	ft_sort(t_data **a, t_data **b, t_data *oper)
{
	static	void (*fnc_actions[])(t_data **a, t_data **b/*, int out*/) = {
		&push_a, &push_b, &swap_a, &swap_b, &swap_ab,
		&rotate_a, &rotate_b, &rotate_ab,
		&rev_rot_a, &rev_rot_b, &rev_rot_ab};

	if (oper)
	{
		while (oper->next)
		{
			fnc_actions[oper->val](a, b/*, 0*/);
			oper = oper->next;
		}
		fnc_actions[oper->val](a, b/*, 0*/);
	}
}
