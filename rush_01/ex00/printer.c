/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:11:52 by mbuchet           #+#    #+#             */
/*   Updated: 2026/02/15 16:32:59 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_putun(unsigned int n);
void	ft_putchar(char c);

void	print_arr(unsigned int *arr, size_t cols, size_t rows)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols - 1)
		{
			ft_putun(arr[i * cols + j]);
			ft_putchar(' ');
			j += 1;
		}
		ft_putun(arr[i * cols + j]);
		ft_putchar('\n');
		i += 1;
	}
}
