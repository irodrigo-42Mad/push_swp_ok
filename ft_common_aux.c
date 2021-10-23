/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:47:17 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/23 20:26:50 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

void	ft_clean_table(char **str)
{
	int	pos;

	pos = -1;
	while (str[++pos])
		free(str);
}

// se cambian los punteros por posiciones.
void	ft_next_stkelm(char *nptr, long *num)
{
	register int	i;

	i = 0;
	while (nptr[i] != '\0')
	{
		if (!ft_isdigit(nptr[i]))
			ft_write_error ("Error:", "");
		*num = (*num) * 10 + (nptr[i] - '0');
		i++;
	}
}

// se cambian los punteros por posiciones.
int	ft_atoi_cnv(char *nptr)
{
	long	num;
	short	sign;

	sign = 1;
	num = 0;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	ft_next_stkelm(nptr, &num);
	if ((sign * num) > INT_MAX || (sign * num) < INT_MIN)
		ft_write_error ("Error:", "");
	return ((int)(sign * num));
}
