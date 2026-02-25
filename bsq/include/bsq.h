/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:37:33 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/25 14:19:45 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "libft.h"

typedef struct s_square
{
	unsigned int	x;	// x-coordinate of the bottom-right corner
	unsigned int	y;	// y-coordinate of the bottom-right corner
	unsigned int	size;
}	t_square;

typedef struct s_map
{
	t_square		biggest;
	unsigned int	*heatmap;
	char			*map;
	size_t			width;	// length of the second line in file
	size_t			height;	// defined by the first line of the map file
	size_t			size;	// width * height
	bool			flipflop;
	// cell characters:
	char			obstacle;
	char			empty;
	char			full;
}	t_map;

bool	parse_map(int fd, t_map *map);
bool	solve(t_map *map);
bool	resize_map(t_map *map);
bool	end_of_file_reached(int fd);
