/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:20:55 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/25 21:58:04 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>	// provides CHAR_BIT, INT_MAX
#include <unistd.h>	// provides read, ssize_t
#include "bsq.h"

/**
 * Extracts the height from a null-terminated string and stores it in the
 * variable pointed to by height.
 *
 * Returns whether the provided nptr is a valid number.
 * To be considered valid, a number MUST:
 * - only be made of decimal digits, and nothing else
 * - fit whithin the range of an int
 */
static bool	parse_height(char *nptr, size_t *height)
{
	unsigned char		digit;
	unsigned int		acc;
	const unsigned int	cutoff = INT_MAX / 10;
	const unsigned int	cutlim = INT_MAX % 10;

	acc = 0;
	digit = (unsigned char)*nptr++ - '0';
	while (digit < 10u)
	{
		if (acc > cutoff || (acc == cutoff && digit > cutlim))
		{
			*height = 0;
			return (false);
		}
		acc = acc * 10 + digit;
		digit = (unsigned char)*nptr++ - '0';
	}
	if (nptr[-1] != '\0')
	{
		*height = 0;
		return (false);
	}
	*height = acc;
	return (true);
}

/**
 * Parses the symbols to use to print the map. The symbols:
 * - must all be different characters
 * - must be printable
 * Returns whether the symbols are all valid.
 */
static bool	parse_symbols(t_map *map, char symbols[3])
{
	if (
		symbols[0] == symbols[1]
		|| symbols[0] == symbols[2]
		|| symbols[1] == symbols[2]
	)
	{
		return (false);
	}
	if (
		!ft_isprint(symbols[0])
		|| !ft_isprint(symbols[1])
		|| !ft_isprint(symbols[2])
	)
	{
		return (false);
	}
	map->empty = symbols[0];
	map->obstacle = symbols[1];
	map->full = symbols[2];
	return (true);
}

/**
 * Parses the "header", i.e. the first line of a BSQ map, which contains the
 * metadata of the map.
 */
static bool	parse_header(int fd, t_map *map)
{
	ssize_t				bytes_read;
	size_t				i;
	char				buffer[(sizeof(int) * CHAR_BIT - 1) * 28 / 93 + 5];

	i = 0;
	bytes_read = read(fd, buffer, 1);
	while (bytes_read > 0)
	{
		if (i >= sizeof buffer - 1)
		{
			return (false);
		}
		if (buffer[i] == '\n')
			break ;
		i += bytes_read;
		bytes_read = read(fd, buffer + i, 1);
	}
	if (bytes_read < 0 || i < 4
		|| !parse_symbols(map, &buffer[i - 3]))
	{
		return (false);
	}
	buffer[i - 3] = '\0';
	return (parse_height(buffer, &map->height));
}

static bool	parse_first_line(int fd, t_map *ctx, size_t *total_read)
{
	ssize_t	bytes_read;
	char	*eol_ptr;

	ctx->size = 1024;
	if (!ft_malloc(&ctx->map, ctx->size))
		return (false);
	*total_read = 0;
	bytes_read = read(fd, ctx->map, ctx->size);
	while (bytes_read > 0)
	{
		eol_ptr = ft_memchr(ctx->map + *total_read, '\n', bytes_read);
		*total_read += bytes_read;
		if (eol_ptr)
		{
			ctx->width = (eol_ptr - ctx->map) + 1;
			return (true);
		}
		if (*total_read == ctx->size && !resize_map(ctx))
			return (false);
		bytes_read = read(fd, ctx->map + *total_read, ctx->size - *total_read);
	}
	if (bytes_read == 0)
		ctx->width = *total_read + 1;
	return (bytes_read >= 0 && *total_read > 0);
}

bool	parse_map(int fd, t_map *ctx)
{
	ssize_t	bytes_read;
	size_t	total_read;

	*ctx = (t_map){0};
	if (!parse_header(fd, ctx))
		return (false);
	if (!parse_first_line(fd, ctx, &total_read))
		return (false);
	ctx->size = ctx->width * ctx->height;
	if (total_read > ctx->size)
		return (false);
	ctx->map = ft_realloc(ctx->map, total_read, ctx->size);
	if (!ctx->map)
		return (false);
	while (total_read < (ctx->size - 1))
	{
		bytes_read = read(fd, ctx->map + total_read, ctx->size - total_read);
		if (bytes_read <= 0)
			return (false);
		total_read += bytes_read;
	}
	if (total_read == ctx->size && ctx->map[ctx->size - 1] != '\n')
		return (false);
	ctx->map[ctx->size - 1] = '\n';
	return (end_of_file_reached(fd));
}
