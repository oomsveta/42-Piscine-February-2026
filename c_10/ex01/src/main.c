/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:41:49 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/09 10:10:48 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>	// provides basename
#include <errno.h>
#include <string.h>
#include "ft.h"

#define BUFFER_SIZE 30720

const char	*g_program_name = NULL;

static void	display_file(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, sizeof buffer);
	while (bytes_read > 0)
	{
		write(STDOUT_FILENO, buffer, bytes_read);
		bytes_read = read(fd, buffer, sizeof buffer);
	}
}

static void	print_error(const char *filename)
{
	const char	*error_msg = strerror(errno);

	write(STDERR_FILENO, g_program_name, ft_strlen(g_program_name));
	write(STDERR_FILENO, ": ", 2);
	if (filename)
	{
		write(STDERR_FILENO, filename, ft_strlen(filename));
		write(STDERR_FILENO, ": ", 2);
	}
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	fd;

	g_program_name = basename(argv[0]);
	if (argc == 1)
	{
		display_file(STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	while (*++argv)
	{
		if (ft_strcmp(*argv, "-") == 0)
		{
			fd = STDIN_FILENO;
		}
		else
		{
			fd = open(*argv, O_RDONLY);
		}
		if (fd == -1)
		{
			print_error(*argv);
			return (EXIT_FAILURE);
		}
		display_file(fd);
		close(fd);
	}
	(void)argc;
}
