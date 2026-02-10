/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:41:49 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/10 20:35:43 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include "ft.h"

#define NO_OPTION -1
#define NAN_OPTION -2
#define MISSING_OPTION -3

const char	*g_program_name = NULL;

int	main(int argc, char *argv[])
{
	ssize_t	nbr_of_bytes;

	g_program_name = *argv++;
	nbr_of_bytes = parse_byte_option(argv);
	if (nbr_of_bytes == NO_OPTION)
	{
		// TODO?
		//return (print_tail(argv));
	}
	if (nbr_of_bytes > 0)
	{
		return (print_last_bytes(argv, nbr_of_bytes));
	}
	return (EXIT_FAILURE);
}
