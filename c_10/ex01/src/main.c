/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:41:49 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/08 22:09:52 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
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

int	main(int argc, char *argv[])
{
	int	fd;

	g_program_name = argv[0];
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
			// TODO
		}
		display_file(fd);
		close(fd);
	}
	(void)argc;
}
