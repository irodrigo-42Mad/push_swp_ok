/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algrthm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:24:51 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/19 13:13:50 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

t_data	*ft_merge(t_data *stk_a, t_data *stk_b)
{
	int	a_elem;

	a_elem = ft_lstlength(stk_a);
	if (ft_order_two(&stk_a, &stk_b))
		return (stk_a);
	while (stk_b && a_elem > 0)
	{
		if (stk_a->val < stk_b->val)
			ft_remv_elm_a(&stk_a, &stk_b, &a_elem);
		else
			ft_remv_elm_b(&stk_a, &stk_b);
	}
	while (a_elem > 0)
		ft_remv_elm_a(&stk_a, &stk_b, &a_elem);
	while (stk_b)
		ft_remv_elm_b(&stk_a, &stk_b);
	return (stk_a);
}

t_data	*ft_merge_sort(t_data *stk_a)
{
	t_data	*stk_b;
	int		elems;

	elems = ft_lstlength(stk_a);
	if (elems <= 1)
		return (stk_a);
	stk_b = ft_stack_split(&stk_a, elems / 2);
	stk_a = ft_merge_sort(stk_a);
	stk_b = ft_merge_sort(stk_b);
	return (ft_merge(stk_a, stk_b));
}
