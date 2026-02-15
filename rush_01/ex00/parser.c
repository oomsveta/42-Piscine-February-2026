/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:11:28 by mbuchet           #+#    #+#             */
/*   Updated: 2026/02/15 22:47:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>			// provides UINT_MAX
#include <stdbool.h>		// provides bool, false, true
#include <stdlib.h>			// provides malloc, NULL, size_t
#include "skyscrapers.h"	// provides t_board

int		ft_isdigit(int c);

/**
 * Parses an unsigned integer from the string pointed to by @p nptr.
 *
 * The pointer is advanced past all consecutive decimal digits that form the
 * number. If an error occurs, parsing stops immediately and 0 is returned.
 *
 * Errors include:
 * - A leading zero (e.g., "0123")
 * - Overflow beyond UINT_MAX

 * In the context of puzzle clues, 0 is not a valid value, making it a suitable
 * sentinel to indicate a parsing error.
 *
 * @param nptr Double pointer to the string representation of a number.
 *
 * @return The parsed unsigned integer on success, or 0 on error.
 */
static unsigned int	parse_uint(const char **nptr)
{
	unsigned int		result;
	const unsigned int	cutoff = UINT_MAX / 10;
	const unsigned int	cutlim = UINT_MAX % 10;
	unsigned char		digit;

	result = 0;
	if (**nptr == '0')
	{
		return (0);
	}
	while (ft_isdigit(**nptr))
	{
		digit = **nptr - '0';
		if (result > cutoff || (result == cutoff && digit > cutlim))
		{
			return (0);
		}
		result = result * 10 + digit;
		*nptr += 1;
	}
	return (result);
}

/**
 * Parses the number of clues from the input string and deduces the grid size.
 *
 * The total number of clues must be divisible by 4, since a valid Skyscrapers
 * puzzle has four sides (top, bottom, left, right).
 *
 * The grid size is computed as:
 *     size = number_of_clues / 4
 *
 * The function fails if:
 * - A non-digit character (other than a separating space) is encountered
 * - A space appears at the end of the string
 * - The total number of clues is not divisible by 4
 *
 * On success, board->size is set accordingly.
 *
 * @param board The puzzle state to initialize.
 * @param arg   The input string containing space-separated clues.
 *
 * @return true if the grid size could be determined successfully; false
 *         otherwise.
 */
static bool	parse_grid_size(t_board *board, const char *arg)
{
	size_t	count;

	count = 0;
	while (*arg != '\0')
	{
		if (!ft_isdigit(*arg))
			return (false);
		count += 1;
		while (ft_isdigit(*arg))
		{
			arg += 1;
		}
		if (*arg == ' ')
		{
			arg += 1;
			if (*arg == '\0')
			{
				return (false);
			}
		}
	}
	board->size = count / 4;
	return (count % 4 == 0);
}

/**
 * Parses and stores all visibility clues from the input string.
 *
 * Each clue must be in the range [1, size]; otherwise the function fails.
 *
 * @param board The puzzle state where clues will be stored.
 * @param str   The input string containing all clues separated by spaces.
 *
 * @return true on successful parsing and allocation;
 *         false if memory allocation fails or an invalid clue is found.
 */
static bool	parse_clues(t_board *board, const char *str)
{
	unsigned int	n;
	const size_t	nbr_of_clues = board->size * 4;
	size_t			i;

	board->all_clues = malloc(sizeof(int) * (4 * board->size));
	if (board->all_clues == NULL)
	{
		return (false);
	}
	i = 0;
	while (i < nbr_of_clues)
	{
		n = parse_uint(&str);
		if (n == 0 || n > board->size)
			return (false);
		board->all_clues[i] = n;
		str += 1;
		i += 1;
	}
	board->clues_top = &board->all_clues[board->size * 0];
	board->clues_bot = &board->all_clues[board->size * 1];
	board->clues_left = &board->all_clues[board->size * 2];
	board->clues_right = &board->all_clues[board->size * 3];
	return (true);
}

/**
 * Prunes impossible opposite-side clue combinations early:
 * - The clues from opposite sides can't both be 1 (unless the size of the grid
 *   is 1).
 * - The sum of clues from opposite sides (e.g., Left + Right) can never exceed
 *   the grid size + 1.
 *
 * @param board The current state of the puzzle.
 *
 * @return Whether all opposite-side clue pairs are potentially valid.
 */
static bool	validate_clues(t_board *board)
{
	size_t				i;
	const unsigned int	max_visibility_sum = board->size + 1;

	i = 0;
	while (i < board->size)
	{
		if (board->clues_top[i] + board->clues_bot[i] > max_visibility_sum)
			return (false);
		if (board->clues_left[i] + board->clues_right[i] > max_visibility_sum)
			return (false);
		if (board->size != 1)
		{
			if (board->clues_left[i] == 1 && board->clues_right[i] == 1)
				return (false);
			if (board->clues_top[i] == 1 && board->clues_bot[i] == 1)
				return (false);
		}
		i += 1;
	}
	return (true);
}

bool	parse_args(t_board *board, const char *arg)
{
	if (!parse_grid_size(board, arg))
	{
		return (false);
	}
	if (!parse_clues(board, arg))
	{
		return (false);
	}
	if (!validate_clues(board))
	{
		return (false);
	}
	return (true);
}
