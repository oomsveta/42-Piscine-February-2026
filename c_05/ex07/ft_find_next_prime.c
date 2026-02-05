/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:33:10 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/05 22:49:03 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>		// provides CHAR_BIT
#include <stdbool.h>	// provides bool, false, true

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

static bool	ft_is_prime(unsigned int n)
{
	const unsigned int	sqrt = ft_sqrt(n);
	unsigned int		try;

	if (n <= 1)
	{
		return (false);
	}
	if (n <= 3)
	{
		return (true);
	}
	if (n % 2 == 0 || n % 3 == 0)
	{
		return (false);
	}
	try = 5;
	while (try <= sqrt)
	{
		if (n % try == 0 || n % (try + 2) == 0)
		{
			return (false);
		}
		try += 6;
	}
	return (true);
}

int	ft_find_next_prime(int nb)
{
	unsigned int	try;

	if (nb <= 2)
	{
		return (2);
	}
	try = (unsigned int)nb + (nb % 2 == 0);
	while (!ft_is_prime(try))
	{
		try += 2;
	}
	return ((int)try);
}

#ifdef TEST

// run with test main:
// clang ft_find_next_prime.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	assert(ft_find_next_prime(3) == 3);
	assert(ft_find_next_prime(4) == 5);
	assert(ft_find_next_prime(14) == 17);
	assert(ft_find_next_prime(-42) == 2);
	assert(ft_find_next_prime(-2147483648) == 2);
	assert(ft_find_next_prime(0) == 2);
	assert(ft_find_next_prime(1) == 2);
	assert(ft_find_next_prime(2) == 2);
	assert(ft_find_next_prime(121) == 127);
	assert(ft_find_next_prime(2147483647) == 2147483647);
	assert(ft_find_next_prime(2147483630) == 2147483647);
	puts("✅ All tests passed");
}

#endif
