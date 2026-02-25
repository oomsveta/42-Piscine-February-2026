/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:29:52 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/25 14:38:14 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides read
#include "bsq.h"	// provides t_map

bool	end_of_file_reached(int fd)
{
	char	garbage;

	return (read(fd, &garbage, 1) <= 0);
}

bool	resize_map(t_map *map)
{
	map->map = ft_realloc(map->map, map->size, map->size * 2);
	if (!map->map)
	{
		map->size = 0;
		return (false);
	}
	map->size *= 2;
	return (true);
}
