/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:09:30 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/25 15:09:22 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>	// provides open, O_RDONLY
#include <stdlib.h>	// provides free, EXIT_SUCCESS, NULL
#include <unistd.h>	// provides close, STDIN_FILENO, STDOUT_FILENO, write
#include "bsq.h"	// provides parse_map, solve, t_map

static void	write_map(t_map *ctx)
{
	ssize_t	bytes_written;
	size_t	left_to_write;
	size_t	offset;

	left_to_write = ctx->size;
	offset = 0;
	while (left_to_write != 0)
	{
		bytes_written = write(STDOUT_FILENO, ctx->map + offset, left_to_write);
		if (bytes_written == -1)
		{
			return ;
		}
		offset += bytes_written;
		left_to_write -= bytes_written;
	}
}

static void	free_resources(t_map *ctx)
{
	free(ctx->heatmap);
	free(ctx->map);
	*ctx = (t_map){0};
}

static void	process_file(int fd)
{
	t_map	ctx;

	if (!parse_map(fd, &ctx) || !solve(&ctx))
	{
		ft_puts("map error");
		free_resources(&ctx);
		return ;
	}
	write_map(&ctx);
	free_resources(&ctx);
}

static void	process_arguments(const char *args[])
{
	int		fd;
	bool	first;

	first = true;
	while (*args != NULL)
	{
		if (!first)
		{
			ft_puts("");
		}
		first = false;
		fd = open(*args, O_RDONLY);
		args += 1;
		if (fd == -1)
		{
			ft_puts("map error");
			continue ;
		}
		process_file(fd);
		close(fd);
	}
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		process_file(STDIN_FILENO);
		return (EXIT_SUCCESS);
	}
	process_arguments((const char **)argv + 1);
}
