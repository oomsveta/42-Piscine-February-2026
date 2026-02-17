/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:41:49 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/19 09:36:52 by lwicket          ###   ########.fr       */
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

static void	print_error(const char *filename)
{
	const char	*error_msg = strerror(errno);

	write(STDERR_FILENO, g_program_name, ft_strlen(g_program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, filename, ft_strlen(filename));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
}

static void	print_header(const char *filename)
{
	write(STDOUT_FILENO, "==> ", 4);
	write(STDOUT_FILENO, filename, ft_strlen(filename));
	write(STDOUT_FILENO, " <==\n", 5);
}

int	tail_stream(int fd, int n)
{
	t_ring_buffer	ring_buffer;
	char			read_buffer[READ_SIZE];
	ssize_t			bytes_read;
	int				bytes_written;
	size_t			i;

	if (n == 0)
	{
		bytes_read = read(fd, read_buffer, READ_SIZE);
		while (bytes_read > 0)
		{
			bytes_read = read(fd, read_buffer, READ_SIZE);
		}
		return (bytes_read);
	}
	ring_buffer = init_ring_buffer(n);
	if (!ring_buffer.data)
	{
		return (-1);
	}
	bytes_read = read(fd, read_buffer, READ_SIZE);
	while (bytes_read > 0)
	{
		i = 0;
		while (i < (size_t)bytes_read)
		{
			append_to_ring_buffer(&ring_buffer, read_buffer[i]);
			i += 1;
		}
		bytes_read = read(fd, read_buffer, READ_SIZE);
	}
	bytes_written = print_ring_buffer(&ring_buffer);
	free_ring_buffer(&ring_buffer);
	return (bytes_written);
}

int	tail(const char *filename, ssize_t nbr_of_bytes, bool should_print_header)
{
	const t_file	file = open_file(filename);

	if (file.fd == -1)
	{
		print_error(file.name);
		return (-1);
	}
	if (should_print_header)
	{
		print_header(file.name);
	}
	if (tail_stream(file.fd, nbr_of_bytes) < 0)
	{
		print_error(file.name);
		close_file(file);
		return (-1);
	}
	if (close_file(file) == -1)
	{
		print_error(file.name);
		return (-1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	const ssize_t	nbr_of_bytes = parse_byte_option((const char **)argv + 1);
	const size_t	nbr_of_files = count_filenames((const char **)argv + 1);
	const bool		should_print_header = nbr_of_files > 1;
	int				exit_status;

	g_program_name = *argv++;
	if (nbr_of_bytes < 0)
	{
		puts("[DEBUG] no options");
		return (EXIT_FAILURE);
	}
	if (nbr_of_files == 0)
	{
		puts("[DEBUG] no args");
		return (tail("-", nbr_of_bytes, should_print_header));
	}
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
