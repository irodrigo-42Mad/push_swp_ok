/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_primary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:58:29 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/23 10:43:46 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

void	ft_new_sglimit(t_data *stk, t_data *lim)
{
	t_bool	status;

	status = FALSE;
	while (lim && stk && !status)
	{
		if (stk->next != lim)
			stk = stk->next;
		else
			status = TRUE;
	}
	if (stk && lim)
		stk->seg_lim = 1;
}

void	ft_set_sgimit(t_data **b, int *lim_set_state)
{
	if (lim_set_state)
		(*b)->seg_lim = 0;
	else
	{
		(*b)->seg_lim = 1;
		*lim_set_state = 1;
	}
}

int	ft_segment_len(t_data *a)
{
	int	n_elm;

	n_elm = 0;
	while (a && !a->seg_lim && a->pos)
	{
		a = a->next;
		n_elm++;
	}
	if (a->pos)
		n_elm++;
	return (n_elm);
}
