/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swp_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:56:40 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/22 13:59:06 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

short	ft_has_sorted(t_data *start, int length, short order)
{
	t_data	*next;

	while (length > 1)
	{
		next = start->next;
		if (order == ACTIVE && start->val > next->val)
			return (0);
		if (order == INACTIVE && start->val < next->val)
			return (0);
		start = next;
		length--;
	}
	return (1);
}

short	ft_min_max(t_data *stk)
{
	t_data	*srt;
	int		n_elm;

	n_elm = ft_lstlength(stk);
	srt = ft_stack_pop(stk, n_elm);
	srt = ft_merge_sort(srt);
	return ((short)(ft_getlast(srt)->val == ft_getlast(stk)->val)
		   || (short)(ft_getlast(srt)->val == stk->val)
		   || (short)(srt->val == stk->val));
}

short	ft_exist_left_val(t_data *b, t_data *pivot)
{
	while (b)
	{
		if (b->val > pivot->val)
			return (1);
		b = b->next;
	}
	return (0);
}
