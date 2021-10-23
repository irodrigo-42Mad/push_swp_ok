/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:53:42 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/23 11:47:00 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

int	main(int argc, char **argv)
{
	t_data	*instr;
	t_data	*a;
	t_data	*b;

	if (argc < 2)
		exit(ft_put_error("Error:", "", 0));
	a = ft_init_stk(&argv[1]); //+  ft_take_options(argc, &argv[1])]); esta última funcion sobra
	b = NULL;
	ft_sort_algrthm(&a);

	


	// hasta aqui está revisado
	
	
	// falta la funcion de normalizar
	//normalize(&a);
	instr = ft_getlist_instr();
	// falta la funcion de ordenar
	ft_sort(&a, &b, instr);
	// falta la funcion de contar las operaciones.
	//op_count(instr);
	checker(a, b);
	return (0);
}
