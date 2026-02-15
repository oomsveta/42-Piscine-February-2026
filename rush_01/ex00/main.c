/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:31:41 by nwatelle          #+#    #+#             */
/*   Updated: 2026/02/15 22:52:39 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"
#include <stdbool.h>
#include <stdlib.h>

void	ft_puts(const char *str);
bool	parse_args(t_board *board, const char *arg);
void	print_arr(unsigned int *arr, size_t cols, size_t rows);
void	ft_bzero(void *ptr, size_t n);
bool	solve(t_board *board);

static void	free_resources(t_board *board)
{
	free(board->all_clues);
	board->all_clues = NULL;
	free(board->grid);
	board->grid = NULL;
}

static unsigned int	*init_grid(unsigned int grid_width)
{
	const size_t	size = sizeof(int) * grid_width * grid_width;
	unsigned int	*grid;

	grid = malloc(size);
	if (!grid)
	{
		return (NULL);
	}
	ft_bzero(grid, size);
	return (grid);
}

/**
 * Entry point for the Skyscrapers puzzle solver.
 *
 * The program expects a single command-line argument: a string of space-
 * separated numbers representing the visibility clues for the puzzle.
 *
 * The clues must be provided in the following order:
 * - Top side, left to right
 * - Bottom side, left to right
 * - Left side, top to bottom
 * - Right side, top to bottom
 *
 * Each clue must be an integer in the range [1, size], and the total number
 * of clues must be exactly 4 * size. For example:
 *
 * 5x5 puzzle:
 * ./rush01 "3 2 2 1 5 2 3 2 4 1 4 2 3 1 2 2 3 2 2 1"
 *
 * 6x6 puzzle:
 * ./rush01 "3 2 2 3 2 1 3 4 2 2 1 5 4 2 2 1 2 3 1 2 3 3 2 2"
 *
 * The program prints the solved grid to standard output, or "Error" if the
 * input is invalid or no solution exists.
 *
 * @param argc The argument count (must be 2).
 * @param argv The argument array containing the clues string.
 */
int	main(int argc, char *argv[])
{
	t_board	board;

	if (argc != 2 || !parse_args(&board, argv[1]))
	{
		ft_puts("Error");
		return (0);
	}
	board.grid = init_grid(board.size);
	if (board.grid == NULL)
	{
		free(board.all_clues);
		ft_puts("Error");
		return (0);
	}
	if (!solve(&board))
	{
		ft_puts("Error");
		return (0);
	}
	print_arr(board.grid, board.size, board.size);
	free_resources(&board);
}
