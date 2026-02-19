/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:49:19 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/19 14:47:38 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include "ft.h"
#include "ft_tail.h"

#define READ_SIZE 4096

static void	print_header(const char *filename)
{
	static bool	is_first = true;

	if (!is_first)
	{
		write(STDOUT_FILENO, "\n", 1);
	}
	is_first = false;
	write(STDOUT_FILENO, "==> ", 4);
	write(STDOUT_FILENO, filename, ft_strlen(filename));
	write(STDOUT_FILENO, " <==\n", 5);
}

static ssize_t	consume_stream(int fd, char *buffer, size_t buffer_size)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, buffer_size);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, buffer_size);
	}
	return (bytes_read);
}

static int	tail_stream(int fd, int n)
{
	t_ring_buffer	ring_buffer;
	char			read_buffer[READ_SIZE];
	ssize_t			bytes_read;
	int				bytes_written;
	size_t			i;

	if (n == 0)
		return (consume_stream(fd, read_buffer, sizeof read_buffer));
	ring_buffer = init_ring_buffer(n);
	if (!ring_buffer.data)
		return (-1);
	bytes_read = read(fd, read_buffer, sizeof read_buffer);
	while (bytes_read > 0)
	{
		i = 0;
		while (i < (size_t)bytes_read)
		{
			append_to_ring_buffer(&ring_buffer, read_buffer[i]);
			i += 1;
		}
		bytes_read = read(fd, read_buffer, sizeof read_buffer);
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
		print_errno(file.name);
		return (-1);
	}
	if (should_print_header)
	{
		print_header(file.name);
	}
	if (tail_stream(file.fd, nbr_of_bytes) < 0)
	{
		print_errno(file.name);
		close_file(file);
		return (-1);
	}
	if (close_file(file) == -1)
	{
		print_errno(file.name);
		return (-1);
	}
	return (0);
}
