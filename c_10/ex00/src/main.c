/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:47:35 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/08 18:22:32 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>	// provides open, O_RDONLY
#include <stdlib.h>	// provides EXIT_FAILURE
#include <unistd.h>	// provides close, ssize_t, STDOUT_FILENO, read, write
#include "ft.h"		// provides ft_puts

#define BUFFER_SIZE 262144

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

int	main(int argc, char *argv[])
{
	int		fd;

	if (argc <= 1)
	{
		ft_puts("File name missing.");
		return (EXIT_FAILURE);
	}
	if (argc != 2)
	{
		ft_puts("Too many arguments.");
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_puts("Cannot read file.");
		return (EXIT_FAILURE);
	}
	display_file(fd);
	close(fd);
}
