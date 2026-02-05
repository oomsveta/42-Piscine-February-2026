/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:40:39 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/05 22:46:03 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

#include <limits.h>	// provides CHAR_BIT

// Quadratic residues mod 16 are 0, 1, 4, and 9.
// Corresponding bitset: 0000 0010 0001 0011 (0x0213 in hex).
#define QUAD_RESIDUES_MOD16 0x0213u

// Align place with the actual magnitude of n.
static inline unsigned int	align_place(unsigned int n)
{
	unsigned int	place;

	place = 1u << (sizeof(int) * CHAR_BIT - 2);
	while (place > n)
	{
		place >>= 2;
	}
	return (place);
}

/**
 * 1. Filter out inputs that definitely aren't perfect squares.
 * 2. Align place with the magnitude of n to avoid iterating over empty space.
 * 3. Perform binary "long division".
 *
 * Long division algorithm based on:
 * https://en.wikipedia.org/wiki/Square_root_algorithms
 */
int	ft_sqrt(int n)
{
	unsigned int	remainder;
	unsigned int	root;
	unsigned int	place;

	if (n < 0 || !((QUAD_RESIDUES_MOD16 >> (n & 15)) & 1))
		return (0);
	root = 0;
	remainder = (unsigned int)n;
	place = align_place((unsigned int)n);
	while (place != 0)
	{
		if (remainder >= root + place)
		{
			remainder -= root + place;
			root += place << 1;
		}
		root >>= 1;
		place >>= 2;
	}
	if (remainder != 0)
	{
		return (0);
	}
	return ((int)root);
}

#ifdef TEST

// run with test main:
// clang ft_sqrt.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	assert(ft_sqrt(2147395600) == 46340);
	assert(ft_sqrt(2147395601) == 0);
	assert(ft_sqrt(2147302921) == 46339);
	assert(ft_sqrt(2147483647) == 0);
	assert(ft_sqrt(2147483641) == 0);
	assert(ft_sqrt(2000000000) == 0);
	assert(ft_sqrt(-1) == 0);
	assert(ft_sqrt(-2147483648) == 0);
	assert(ft_sqrt(0) == 0);
	assert(ft_sqrt(1) == 1);
	assert(ft_sqrt(2) == 0);
	assert(ft_sqrt(25) == 5);
	assert(ft_sqrt(99) == 0);
	assert(ft_sqrt(2147302922) == 0);
	assert(ft_sqrt(7) == 0);
	puts("✅ All tests passed");
}

#endif
