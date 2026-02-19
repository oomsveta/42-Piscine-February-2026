/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:41:49 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/19 15:30:57 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "ft_tail.h"
#include "ft.h"

#define NO_OPTION -1
#define NAN_OPTION -2
#define MISSING_OPTION -3

const char	*g_program_name = NULL;

void	print_error(const char *msg, const char *extra)
{
	write(STDERR_FILENO, g_program_name, ft_strlen(g_program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	if (extra)
	{
		write(STDERR_FILENO, "‘", sizeof "‘" - 1);
		write(STDERR_FILENO, extra, ft_strlen(extra));
		write(STDERR_FILENO, "’", sizeof "’" - 1);
	}
	write(STDERR_FILENO, "\n", 1);
}

void	print_errno(const char *filename)
{
	const char	*error_msg = strerror(errno);

	write(STDERR_FILENO, g_program_name, ft_strlen(g_program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, filename, ft_strlen(filename));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
}

int	main(int argc, char *argv[])
{
	ssize_t			nbr_of_bytes;
	const size_t	nbr_of_files = count_filenames((const char **)argv + 1);
	const bool		should_print_header = nbr_of_files > 1;
	int				exit_status;

	g_program_name = *argv++;
	nbr_of_bytes = parse_byte_option((const char **)argv);
	if (nbr_of_bytes < 0)
		return (nbr_of_bytes == NO_OPTIONS);
	if (nbr_of_files == 0)
		return (tail("-", nbr_of_bytes, should_print_header));
	exit_status = 0;
	while (*argv != NULL)
	{
		if (ft_strncmp(*argv, "-c", 2) == 0)
		{
			argv += 1 + ((*argv)[2] == '\0');
			continue ;
		}
		exit_status |= tail(*argv, nbr_of_bytes, should_print_header);
		argv += 1;
	}
	(void)argc;
	return (exit_status);
}
