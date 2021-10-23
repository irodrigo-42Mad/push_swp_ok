/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:49:21 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/21 13:29:12 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprimary.h"

t_boolean	ft_strnbr(char *str)
{
	int	pos;

	pos = -1;
	while (str[++pos])
	{
		if (str[pos] == '-' || str[pos] == '+'
			|| (str[pos] >= '0' && str[pos] <= '9'))
			pos++;
		else
			return (FALSE);
	}
	return (TRUE);
}

// estoy por aqui haciendo cosas

/*static void	usage(void)
{
	printf("usage: ./checker [-v:<frame_delay>] [-p:<frame_delay>] [-c]\n\n");
	printf("Check push_swap output:\n");
	printf("-v: visualize operations.\n");
	printf("-p: print stacks after exexuting instructions\n");
	printf("-c: print number of push_swap instruction\n\n");
	printf("NOTE: [-v] and [-p] cannot coexist\n\n");
	exit(1);
}

static void	get_frame_delay(char *argv, t_op *options)
{
	while (*argv && *argv != ':')
		argv++;
	argv++;
	if (!string_is_num(argv))
		error();
	options->frame_delay = simple_atoi(argv);
}*/

void	extract_option(char *argv, t_op *options)
{
	if (ft_strncmp(argv, "-h", 3) == 0)
		usage();
	else if (ft_strncmp(argv, "-v:", 3) == 0)
	{
		if (options->visualize || options->frame_delay)
			error();
		get_frame_delay(argv, options);
		options->visualize = 1;
	}
	else if (ft_strncmp(argv, "-p:", 3) == 0)
	{
		if (options->print || options->frame_delay)
			error();
		get_frame_delay(argv, options);
		options->print = 1;
	}
	else if (ft_strncmp(argv, "-c", 3) == 0)
	{
		if (options->count)
			error();
		options->count = 1;
	}
	else
		error();
}

short	ft_take_options(int argc, char **argv)
{
	short	i;

	i = 0;
	while (argv[i] && !ft_strnbr(argv[i]))
	{
		extract_option(argv[i], /*options*/);
		i++;
	}
	if (argc <= i + 1)
		ft_write_error("error", "");
	return (i);
}
