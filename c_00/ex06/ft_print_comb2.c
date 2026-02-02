/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:31:06 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/02 22:58:38 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides STDOUT_FILENO, write

// Number of combinations: 100!/(2!(100-2)!) = 4950 combinations.
// Checking the number of combinations: ./a.out | tr ',' '\n' | grep -c .

void	ft_print_comb2(void)
{
	char			comb[7];
	unsigned int	i;
	unsigned int	j;

	comb[2] = ' ';
	comb[5] = ',';
	comb[6] = ' ';
	i = 0;
	while (i < 98)
	{
		j = i + 1;
		comb[0] = i / 10 | '0';
		comb[1] = i % 10 | '0';
		while (j <= 99)
		{
			comb[3] = j / 10 | '0';
			comb[4] = j % 10 | '0';
			write(STDOUT_FILENO, comb, sizeof comb);
			j += 1;
		}
		i += 1;
	}
	write(STDOUT_FILENO, "98 99", 5);
}
