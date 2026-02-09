/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:41:49 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/09 14:05:10 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides EXIT_FAILURE, EXIT_SUCCESS
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <libgen.h>	// provides basename
#include <errno.h>
#include <string.h>
#include "ft.h"

#define BUFFER_SIZE 30720

static ssize_t	display_file(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	ssize_t	file_size;

	file_size = 0;
	bytes_read = read(fd, buffer, sizeof buffer);
	while (bytes_read > 0)
	{
		if (bytes_read == -1)
		{
			return (-1);
		}
		file_size += bytes_read;
		if (write(STDOUT_FILENO, buffer, bytes_read) == -1)
		{
			return (-1);
		}
		bytes_read = read(fd, buffer, sizeof buffer);
	}
	return (file_size);
}

static void	print_error(const char *program_name, const char *filename)
{
	const char	*error_msg = strerror(errno);

	write(STDERR_FILENO, program_name, ft_strlen(program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, filename, ft_strlen(filename));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
}

int	main(int argc, char *argv[])
{
	const char	*program_name = basename(argv[0]);
	const char	*filename = "-";
	int			fd;
	int			status;

	status = EXIT_SUCCESS;
	if (argc > 1)
		filename = *++argv;
	while (filename && status == EXIT_SUCCESS)
	{
		if (ft_strcmp(filename, "-") == 0)
			fd = STDIN_FILENO;
		else
			fd = open(filename, O_RDONLY);
		if (fd == -1 || display_file(fd) == -1)
		{
			print_error(program_name, filename);
			status = EXIT_FAILURE;
		}
		if (fd != STDIN_FILENO)
			close(fd);
		filename = *++argv;
	}
	return (status);
}
