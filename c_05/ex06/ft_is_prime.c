/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:44:43 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/05 22:46:44 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

#include <limits.h>	// provides CHAR_BIT

static unsigned int	ft_sqrt(unsigned int n)
{
	unsigned int	root;
	unsigned int	place;

	if (n < 2)
	{
		return (n);
	}
	root = 0;
	place = 1u << (sizeof(int) * CHAR_BIT - 2);
	while (place > n)
	{
		place >>= 2;
	}
	while (place != 0)
	{
		if (n >= root + place)
		{
			n -= root + place;
			root += place << 1;
		}
		root >>= 1;
		place >>= 2;
	}
	return (root);
}

// Trial Division with Wheel Factorization (6k ± 1) up to the square root.
int	ft_is_prime(int nb)
{
	const unsigned int	un = (unsigned int)nb;
	const unsigned int	sqrt = ft_sqrt(un);
	unsigned int		try;

	if (nb == 2 || nb == 3)
	{
		return (1);
	}
	if (nb < 2 || nb % 2 == 0 || nb % 3 == 0)
	{
		return (0);
	}
	try = 5;
	while (try <= sqrt)
	{
		if (un % try == 0 || un % (try + 2) == 0)
		{
			return (0);
		}
		try += 6;
	}
	return (1);
}

#ifdef TEST

// run with test main:
// clang ft_is_prime.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	assert(ft_is_prime(7) == 1);
	assert(ft_is_prime(11) == 1);
	assert(ft_is_prime(2147483647) == 1);
	assert(ft_is_prime(9) == 0);
	assert(ft_is_prime(25) == 0);
	assert(ft_is_prime(3) == 1);
	assert(ft_is_prime(4) == 0);
	assert(ft_is_prime(5) == 1);
	assert(ft_is_prime(1) == 0);
	assert(ft_is_prime(0) == 0);
	assert(ft_is_prime(-1) == 0);
	assert(ft_is_prime(2147483563) == 1);
	assert(ft_is_prime(1147430897) == 1);
	assert(ft_is_prime(11) == 1);
	puts("✅ All tests passed");
}

#endif
