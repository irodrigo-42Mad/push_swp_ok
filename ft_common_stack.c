/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:07:20 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/22 13:25:28 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

void	ft_replace(t_data *src, t_data *dest, int val)
{
	t_boolean	end;

	end = FALSE;
	while (dest && !end)
	{
		if (src->val != dest->val)
			dest = dest->next;
		else
			end = TRUE;
	}
	if (dest != NULL)
		dest->pos = val;
}

t_data	*ft_stack_pop(t_data *first, int pos)
{
	t_data	*stk;

	stk = NULL;
	while (pos)
	{
		ft_addlst(&stk, first->val);
		first = first->next;
		pos--;
	}
	return (stk);
}

t_data	*ft_init_stk(char **nums)
{
	t_data	*stk;

	stk = NULL;
	while (*nums)
	{
		ft_addlst(&stk, ft_atoi_cnv(*nums));
		nums++;
	}
	ft_clean_table(nums);
	return (stk);
}

/*t_data	*ft_partial_sort_stk(t_data *first, int len)
{
	t_data	*stk;

	stk = ft_stack_pop(first, len);
	// tengo que comprobar por que sacamos todos los el
	// y ordenamos el resto
	stk = ft_merge_sort(stk);
	return (stk);
}*/

//cambiar aqui el partial sort por las llamadas independientes
	//ok_stk = ft_partial_sort_stk(*el, lst_len(*el));

void	ft_sort_algrthm(t_data **el)
{
	int			len;
	int			i;
	t_data		*ok_stk;

	i = -1;
	len = ft_lstlength(*el);
	ok_stk = ft_stack_pop(*el, len);
	ok_stk = ft_merge_sort(ok_stk);
	while (++i < len)
	{
		ft_replace(ok_stk, *el, i);
		ok_stk = ok_stk->next;
	}
}
