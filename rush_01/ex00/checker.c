/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:53:22 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/15 22:19:14 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>		// provides bool, false, true
#include <stddef.h>			// provides size_t
#include "skyscrapers.h"	// provides t_board

/**
 * Counts the number of visible skyscrapers along a specific line of sight.
 *
 * @param start  Pointer to the first cell (the one closest to the observer).
 * @param size   The size of the grid (N).
 * @param step   The index jump to the next cell:
 *                1: Left -> Right
 *               -1: Right -> Left
 *                N: Top -> Bottom
 *               -N: Bottom -> Top
 *
 * @return The count of visible skyscrapers from the given perspective.
 */
static unsigned int	count_visible(unsigned int *start, size_t size, int step)
{
	size_t			i;
	unsigned int	visible_count;
	unsigned int	max_height;
	unsigned int	current_height;

	visible_count = 0;
	max_height = 0;
	i = 0;
	while (i < size)
	{
		current_height = start[i * step];
		if (current_height > max_height)
		{
			max_height = current_height;
			visible_count += 1;
		}
		i += 1;
	}
	return (visible_count);
}

/**
 * Checks that no building with the given height already exists in the
 * specified row or column.
 *
 * @param board  The current state of the puzzle.
 * @param x      The x-coordinate of the column to check.
 * @param y      The y-coordinate of the row to check.
 * @param height The height of the building to test for uniqueness.
 *
 * @return true if no other building of this height exists in the given row or
 *         column; false otherwise.
 */
bool	check_uniqueness(
	t_board *board, size_t x, size_t y, unsigned int height
)
{
	size_t	i;

	i = 0;
	while (i < board->size)
	{
		if (board->grid[y * board->size + i] == height)
		{
			return (false);
		}
		if (board->grid[i * board->size + x] == height)
		{
			return (false);
		}
		i += 1;
	}
	return (true);
}

/**
 * Checks whether the current row and column satisfy the visibility constraints
 * (line-of-sight clues) after placing a building at (x, y).
 *
 * This function verifies that:
 * - The number of visible buildings from the left and top does not exceed the
 *   corresponding clues.
 * - If the row is complete (x is the last column), the left and right clues are
 *   matched exactly.
 * - If the column is complete (y is the last row), the top and bottom clues are
 *   matched exactly.
 *
 * @param board The current state of the puzzle.
 * @param x     The x-coordinate of the recently updated cell.
 * @param y     The y-coordinate of the recently updated cell.
 *
 * @return true if the visibility constraints are satisfied for the affected row
 *         and column; false otherwise.
 */
bool	check_line_of_sight(t_board *board, size_t x, size_t y)
{
	const size_t	n = board->size;
	unsigned int	*grid;

	grid = board->grid;
	if (count_visible(&grid[y * n], n, 1) > board->clues_left[y])
		return (false);
	if (x == n - 1)
	{
		if (count_visible(&grid[y * n], n, 1) != board->clues_left[y])
			return (false);
		if (count_visible(
				&grid[y * n + (n - 1)], n, -1) != board->clues_right[y])
			return (false);
	}
	if (count_visible(&grid[x], n, n) > board->clues_top[x])
		return (false);
	if (y == n - 1)
	{
		if (count_visible(&grid[x], n, n) != board->clues_top[x])
			return (false);
		if (count_visible(&grid[(n - 1) * n + x], n, -n) != board->clues_bot[x])
			return (false);
	}
	return (true);
}
