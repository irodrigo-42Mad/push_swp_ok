/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:46:28 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/20 11:12:33 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

int	main(int argc, char **argv)
{
	t_data	*a;
	t_data	*b;
	int		len;

	len = 0;
	if (argc < 2)
		exit(ft_put_error("Error:", "", 0));
	a = ft_init_stk(&argv[1]);
	b = NULL;
	ft_sort_algrthm(&a);
	len = ft_lstlength(a);
	if (ft_has_sorted(a, len, ACTIVE))
		exit(0);
	if (len <= 5)
		ft_push_swap_lite(&a, &b, len);
	else
		ft_push_swap_lng(&a, &b, len);
	return (0);
}

/*	if (len <= 5)
		push_swap_small(&a, &b, len);
	else
		push_swap(&a, &b, len);*/