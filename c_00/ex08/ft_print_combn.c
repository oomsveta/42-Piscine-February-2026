/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:57:07 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/02 23:15:42 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>	// provides true
#include <unistd.h>		// provides STDOUT_FILENO, write

// max value for index i: '9' - (distance from end)
// distance from end = (n - 1) - i

void	ft_print_combn(int n)
{
	char	*comb;
	int		i;

	if (n <= 0 || n > 10)
		return ;
	comb = (char []){"0123456789"};
	while (true)
	{
		write(STDOUT_FILENO, comb, n);
		i = n - 1;
		while (i >= 0 && comb[i] == '9' - (n - 1 - i))
		{
			i -= 1;
		}
		if (i < 0)
		{
			return ;
		}
		write(STDOUT_FILENO, ", ", 2);
		comb[i] += 1;
		while (++i < n)
		{
			comb[i] = comb[i - 1] + 1;
		}
	}
}
