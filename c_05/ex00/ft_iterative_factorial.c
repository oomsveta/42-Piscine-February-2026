/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:15:31 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/05 16:21:17 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

int	ft_iterative_factorial(int nb)
{
	unsigned int	acc;

	if (nb < 0)
	{
		return (0);
	}
	acc = 1;
	while (nb != 0)
	{
		acc *= nb;
		nb -= 1;
	}
	return ((int)acc);
}

#ifdef TEST

// run with test main:
// clang ft_iterative_factorial.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	assert(ft_iterative_factorial(-2147483648) == 0);
	assert(ft_iterative_factorial(-1) == 0);
	assert(ft_iterative_factorial(0) == 1);
	assert(ft_iterative_factorial(2) == 2);
	assert(ft_iterative_factorial(3) == 6);
	assert(ft_iterative_factorial(4) == 24);
	assert(ft_iterative_factorial(5) == 120);
	assert(ft_iterative_factorial(6) == 720);
	assert(ft_iterative_factorial(7) == 5040);
	assert(ft_iterative_factorial(8) == 40320);
	assert(ft_iterative_factorial(9) == 362880);
	assert(ft_iterative_factorial(10) == 3628800);
	assert(ft_iterative_factorial(11) == 39916800);
	assert(ft_iterative_factorial(12) == 479001600);
	puts("✅ All tests passed");
}

#endif
