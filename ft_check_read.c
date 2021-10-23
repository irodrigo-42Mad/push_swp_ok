/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:45:38 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/23 11:48:59 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

int	get_instr(char *action)
{
	int			i;
	static char	*oper[] = {
		"pa", "pb", "sa", "sb", "ss",
		"ra", "rb", "rr",
		"rra", "rrb", "rrr",
	};

	i = 0;
	while (oper[i])
	{
		if (!ft_strncmp(oper[i], action, ft_strlen(action))
			&& !oper[i][ft_strlen(action)])
			return (i);
		i++;
	}
	return (i);
}

t_data	*ft_getlist_instr(void)
{
	// por aqui andurio
	t_data	*instr;
	char	*line;
	int		read;

	instr = NULL;
	read = get_next_line(0, &line);
	while (read)
	{
		if (*line && *line != '\n')
			set_next_instr(line, &instr);
		free(line);
		read = get_next_line(0, &line);
	}
	free(line);
	return (instr);
}

void	set_next_instr(char *el, t_data **ins_lst)
{
	int		num_instr;
	t_data	*last;
	t_data	*next_instr;

	next_instr = malloc(sizeof(t_data));
	if (next_instr)
	{
		num_instr = get_instr(el);
		if (num_instr > 10)
			error();
		next_instr->val = num_instr;
		next_instr->next = NULL;
		if (!*ins_lst)
			*ins_lst = next_instr;
		else
		{
			last = lst_last(*ins_lst);
			last->next = next_instr;
		}
	}
}
