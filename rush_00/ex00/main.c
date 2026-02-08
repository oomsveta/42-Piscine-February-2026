/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:41:44 by cllaurad          #+#    #+#             */
/*   Updated: 2026/02/08 08:59:57 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>	// provides bool, false, true
#include <unistd.h>		// provides STDOUT_FILENO, write

void	ft_putchar(int c);
void	rush(int x, int y);

void	print_line(int width, char left, char mid, char right)
{
	int	i;

	ft_putchar(left);
	i = 2;
	while (i < width)
	{
		ft_putchar(mid);
		i += 1;
	}
	if (width >= 2)
	{
		ft_putchar(right);
	}
	ft_putchar('\n');
}

void	print_map(int width, int height, const char style[6])
{
	int		y;
	bool	is_top_edge;
	bool	is_bottom_edge;

	y = 1;
	while (y <= height)
	{
		is_top_edge = y == 1;
		is_bottom_edge = y == height;
		if (is_top_edge)
		{
			print_line(width, style[0], style[4], style[1]);
		}
		else if (is_bottom_edge)
		{
			print_line(width, style[2], style[4], style[3]);
		}
		else
		{
			print_line(width, style[5], ' ', style[5]);
		}
		y += 1;
	}
}

bool	validate_params(int width, int height)
{
	const char	too_low_error[] = ""
		"Error: x and y must be non-null, positive values.\n";
	const char	too_high_error[] = ""
		"Error: x and/or y are too high (max: 420, 110).\n";

	if (width <= 0 || height <= 0)
	{
		write(STDOUT_FILENO, too_low_error, sizeof too_low_error - 1);
		return (false);
	}
	if (width > 420 || height > 110)
	{
		write(STDOUT_FILENO, too_high_error, sizeof too_high_error - 1);
		return (false);
	}
	return (true);
}

/**
 * @brief Prints a Rush according to the given specifications.
 *
 * This function prints a rectangle with the specified dimensions, using the
 * characters provided in @p style to draw its corners and borders.
 *
 * @param width  The width of the rectangle. Constraint: 0 < width <= 420.
 * @param height The height of the rectangle. Constraint: 0 < height <= 110.
 * @param style  A string containing the characters used to render the corners
 *               and borders of the rectangle:
 *               {
 *                   [0] = top-left corner,
 *                   [1] = top-right corner,
 *                   [2] = bottom-left corner,
 *                   [3] = bottom-right corner,
 *                   [4] = horizontal edges,
 *                   [5] = vertical edges
 *               }
 */
void	rush_generic(int width, int height, const char style[6])
{
	if (!validate_params(width, height))
	{
		return ;
	}
	print_map(width, height, style);
}

int	main(void)
{
	rush(5, 3);
	ft_putchar('\n');
	rush(5, 1);
	ft_putchar('\n');
	rush(1, 1);
	ft_putchar('\n');
	rush(1, 5);
	ft_putchar('\n');
	rush(4, 4);
}
