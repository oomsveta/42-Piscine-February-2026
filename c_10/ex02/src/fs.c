/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:22:50 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/17 10:06:41 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft.h"
#include "ft_tail.h"

#define STDIN_FILENAME "standard input"

t_file	open_file(const char *filename)
{
	int	fd;

	if (ft_streq(filename, "-"))
	{
		return ((t_file){.name = STDIN_FILENAME, .fd = STDOUT_FILENO});
	}
	fd = open(filename, O_RDONLY);
	return ((t_file){.name = filename, .fd = fd});
}

int	close_file(t_file file)
{
	if (ft_streq(file.name, STDIN_FILENAME))
	{
		return (0);
	}
	return (close(file.fd));
}
