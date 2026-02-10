/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:34:49 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/10 10:07:53 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>	// provides bool, false, true
#include <unistd.h>		// provides size_t, STDOUT_FILENO, write

/**
 * The size of the chessboard (and therefore the number of queens to place).
 * Printing the board won't work for N > 10.
 */
#define N 10
#if N < 0 || N > 10

error "N must be between 0 and 10.";

#endif

static unsigned int	ft_abs(int n)
{
	if (n < 0)
	{
		return (-(unsigned int)n);
	}
	return (n);
}

/**
 * @brief Checks that the current configuration is "safe", meaning no queens can
 *        capture each other.
 *
 * A configuration is safe if:
 * - There is only one queen by column.
 * - There is only one queen by diagonals (both major / and minor \).
 *
 * Checking diagonals:
 * ===================
 * Two queens are on the same diagonal if |col1 - col2| = |row1 - row2|:
 *
 *        0   1   2   3
 *    -----------------
 *    0 | Q | . | . | . |    (queen at (0, 0))
 *    1 | . | . | . | Q |    (queen at (1, 3))
 *    2 | . | Q | . | . |    (queen at (2, 1))
 *    3 | . | . | Q | . |    (queen at (3, 2))
 *
 * Queens at (2, 1) and (3, 2) are on the same diagonal since |2 - 3| = |1 - 2|.
 *
 * @param board An array {row => col}.
 * @param new_row The current row being checked for a valid queen placement.
 * @return True if the configuration is safe (no conflicts), false otherwise.
 */
static bool	is_safe(unsigned int board[N], size_t new_row)
{
	size_t			prev_row;
	unsigned int	col_diff;
	unsigned int	row_diff;

	prev_row = 0;
	while (prev_row < new_row)
	{
		if (board[prev_row] == board[new_row])
		{
			return (false);
		}
		col_diff = ft_abs(board[prev_row] - board[new_row]);
		row_diff = new_row - prev_row;
		if (col_diff == row_diff)
		{
			return (false);
		}
		prev_row += 1;
	}
	return (true);
}

static void	print_board(unsigned int board[N])
{
	size_t	i;
	char	c;

	i = 0;
	while (i < N)
	{
		c = board[i] | '0';
		write(STDOUT_FILENO, &c, sizeof c);
		i += 1;
	}
	write(STDOUT_FILENO, "\n", 1);
}

static unsigned int	dfs_solve(unsigned int board[N], size_t current_row)
{
	size_t			col;
	unsigned int	total_solutions;

	if (current_row == N)
	{
		print_board(board);
		return (1);
	}
	total_solutions = 0;
	col = 0;
	while (col < N)
	{
		board[current_row] = col;
		if (is_safe(board, current_row))
		{
			total_solutions += dfs_solve(board, current_row + 1);
		}
		col += 1;
	}
	return (total_solutions);
}

int	ft_ten_queens_puzzle(void)
{
	unsigned int	board[N];
	size_t			i;

	i = 0;
	while (i < N)
	{
		board[i] = 0;
		i += 1;
	}
	return (dfs_solve(board, 0));
}

/* int	main(void)
{
	ft_ten_queens_puzzle();
} */
