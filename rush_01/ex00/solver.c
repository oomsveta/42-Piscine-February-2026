/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 13:11:41 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/15 22:41:25 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>		// provides bool, false, true
#include <stddef.h>			// provides size_t
#include <sys/types.h>		// provides ssize_t
#include "skyscrapers.h"	// provides t_board

bool	check_uniqueness(t_board *board, size_t r, size_t c, unsigned int h);
bool	check_line_of_sight(t_board *b, size_t x, size_t y);

/**
 * Fills a line with deducible values based on a single clue.
 *
 * This function applies two simple deterministic rules:
 * - If the clue is 1, the tallest building (size) must be placed at the
 *   starting position.
 * - If the clue equals the line size, the buildings must appear in strictly
 *   increasing order from 1 to size.
 *
 * The line is traversed using the provided step value, allowing the
 * function to operate on rows or columns in either direction.
 *
 * @param start  Pointer to the first cell of the line.
 * @param size   The number of cells in the line (N).
 * @param step   The index jump to the next cell:
 *                1: Left -> Right
 *               -1: Right -> Left
 *                N: Top -> Bottom
 *               -N: Bottom -> Top
 * @param clue  The visibility clue associated with this line.
 */
static void	fill_line_obvious(
	unsigned int *start, ssize_t size, int step, unsigned int clue
)
{
	ssize_t	i;

	if (clue == 1)
	{
		start[0] = size;
	}
	else if (clue == size)
	{
		i = 0;
		while (i < size)
		{
			start[i * step] = i + 1;
			i += 1;
		}
	}
}

/**
 * Applies obvious deterministic deductions to the entire grid.
 *
 * @param board The current state of the puzzle.
 */
static void	solve_obvious(t_board *board)
{
	const size_t	n = board->size;
	unsigned int	*grid;
	size_t			i;

	grid = board->grid;
	i = 0;
	while (i < n)
	{
		fill_line_obvious(&grid[i], n, n, board->clues_top[i]);
		fill_line_obvious(&grid[(n - 1) * n + i], n, -n, board->clues_bot[i]);
		fill_line_obvious(&grid[i * n], n, 1, board->clues_left[i]);
		fill_line_obvious(&grid[i * n + (n - 1)], n, -1, board->clues_right[i]);
		i += 1;
	}
}

/**
 * Solves the puzzle using recursive backtracking.
 *
 * The function processes the grid linearly using the index @p pos, attempting
 * to assign a valid height to each empty cell.
 *
 * For each position:
 * - If all cells have been processed, the puzzle is solved.
 * - If the current cell is already filled, it validates the current
 *   line-of-sight constraints and proceeds to the next position.
 * - Otherwise, it tries all possible heights in the range [1, size],
 *   checking row/column uniqueness and visibility constraints before
 *   recursing further.
 *
 * If a placement leads to a dead end, the cell is reset to 0
 * (backtracked) and the next height is attempted.
 *
 * @param board The current state of the puzzle.
 * @param pos   The linear index of the cell currently being processed.
 *
 * @return true if a valid solution is found;
 *         false if no solution exists along the current search path.
 */
bool	solve_backtracking(t_board *board, size_t pos)
{
	const size_t	y = pos / board->size;
	const size_t	x = pos % board->size;
	unsigned int	height;

	if (pos == board->size * board->size)
		return (true);
	if (board->grid[pos] != 0)
		return (check_line_of_sight(board, x, y)
			&& solve_backtracking(board, pos + 1));
	height = 1;
	while (height <= board->size)
	{
		if (check_uniqueness(board, x, y, height))
		{
			board->grid[pos] = height;
			if (check_line_of_sight(board, x, y))
			{
				if (solve_backtracking(board, pos + 1))
					return (true);
			}
			board->grid[pos] = 0;
		}
		height += 1;
	}
	return (false);
}

bool	solve(t_board *board)
{
	solve_obvious(board);
	return (solve_backtracking(board, 0));
}
