/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:45:44 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/19 12:42:38 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

void	ft_hasdupl(t_data *stack, int value)
{
	if (stack)
	{
		while (stack->next)
		{
			if (value == stack->val)
				ft_write_error("Error:", "");
			stack = stack->next;
		}
		if (value == stack->val)
			ft_write_error("Error:", "");
	}
}

t_data	*ft_getlast(t_data *stk)
{
	if (!stk)
		return (0);
	while (stk->next != NULL)
		stk = stk->next;
	return (stk);
}

void	ft_addlst(t_data **stk, int val)
{
	t_data	*new;
	t_data	*last;

	if (stk)
	{
		new = malloc(sizeof(t_data));
		if (new)
		{
			ft_hasdupl(*stk, val);
			new->val = val;
			new->seg_lim = 0;
			new->next = NULL;
			if (!*stk)
				*stk = new;
			else
			{
				last = ft_getlast(*stk);
				last->next = new;
			}
		}
	}
}

t_data	*ft_goto_el(t_data *stk, short pos)
{
	if (stk == NULL)
		return (0);
	while (pos > 0)
	{
		stk = stk->next;
		pos--;
	}
	return (stk);
}

int	ft_lstlength(t_data *stk)
{
	int	len;

	len = 0;
	if (stk == NULL)
		return (0);
	while (stk->next)
	{
		stk = stk->next;
		len++;
	}
	len++;
	return (len);
}
