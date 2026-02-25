/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:58:41 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/25 15:01:48 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	//provides malloc
#include "bsq.h"

static void	draw_answer(t_map *map)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	end_x;
	unsigned int	end_y;

	y = map->biggest.y;
	x = map->biggest.x;
	end_x = x + map->biggest.size;
	end_y = y + map->biggest.size;
	while (y < end_y)
	{
		x = map->biggest.x;
		while (x < end_x)
		{
			map->map[y * map->width + x] = map->full;
			++x;
		}
		++y;
	}
}

static size_t	min_neighbors(t_map *ctx, size_t x, size_t y)
{
	unsigned int	min;
	unsigned int	*current_line;
	unsigned int	*previous_line;

	current_line = ctx->heatmap + ctx->flipflop * ctx->width;
	previous_line = ctx->heatmap + !ctx->flipflop * ctx->width;
	if (x == 0 || y == 0)
	{
		return (0);
	}
	min = current_line[x - 1];
	min = ft_umin(min, previous_line[x]);
	return (ft_umin(min, previous_line[x - 1]));
}

static bool	process_line(t_map *map, size_t y)
{
	unsigned int	*curr_line;
	char			curr_chr;
	size_t			x;
	size_t			size;

	curr_line = map->heatmap + map->flipflop * map->width;
	x = 0;
	while (x < map->width - 1)
	{
		size = 0;
		curr_chr = map->map[y * map->width + x];
		if (curr_chr != map->empty && curr_chr != map->obstacle)
		{
			return (false);
		}
		if (curr_chr == map->empty)
			size = min_neighbors(map, x, y) + 1;
		curr_line[x] = size;
		if (size > map->biggest.size)
			map->biggest = (t_square){x + 1 - size, y + 1 - size, size};
		++x;
	}
	map->flipflop = !map->flipflop;
	return (map->map[y * map->width + x] == '\n');
}

bool	solve(t_map *ctx)
{
	size_t	i;

	ctx->heatmap = malloc(sizeof(int) * (2 * ctx->width));
	i = 0;
	while (i < ctx->height)
	{
		if (!process_line(ctx, i))
		{
			return (false);
		}
		i += 1;
	}
	draw_answer(ctx);
	return (true);
}
