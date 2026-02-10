/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:24:24 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/10 15:17:22 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

int	ft_iterative_power(int nb, int power)
{
	int	acc;

	if (power < 0)
	{
		return (0);
	}
	acc = 1;
	while (power != 0)
	{
		acc *= nb;
		power -= 1;
	}
	return (acc);
}

#ifdef TEST

// run with test main:
// clang ft_iterative_power.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	assert(ft_iterative_power(2, 9) == 512);
	assert(ft_iterative_power(-2, 31) == -2147483648);
	assert(ft_iterative_power(0, 0) == 1);
	assert(ft_iterative_power(0, 1) == 0);
	puts("✅ All tests passed");
}

#endif