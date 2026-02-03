/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:44:59 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/03 11:30:37 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
#endif

#include <stddef.h>	// provides size_t

static void	ft_swap(int *restrict a, int *restrict b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void	ft_rev_int_tab(int *tab, int size)
{
	const size_t	mid = size / 2;
	size_t			i;

	i = 0;
	while (i < mid)
	{
		ft_swap(&tab[i], &tab[size - 1 - i]);
		i += 1;
	}
}

#ifdef TEST

// run with test main:
// clang ft_rev_int_tab.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	const int	expected1[] = {3, 2, 1};
	const int	expected2[] = {INT_MAX, 0, -1, INT_MIN};
	int			*test_case;

	test_case = (int []){1, 2, 3};
	ft_rev_int_tab(test_case, sizeof expected1 / sizeof(*expected1));
	assert(memcmp(test_case, expected1, sizeof expected1) == 0);
	test_case = (int []){INT_MIN, -1, 0, INT_MAX};
	ft_rev_int_tab(test_case, sizeof expected2 / sizeof(*expected2));
	assert(memcmp(test_case, expected2, sizeof expected2) == 0);
	puts("✅ All tests passed");
}

#endif
