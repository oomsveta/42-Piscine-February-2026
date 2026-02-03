/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:07:24 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/03 23:53:22 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
#endif

#include <stdbool.h>	// provides bool, false, true
#include <stddef.h>		// provides size_t

static void	ft_swap(int *restrict a, int *restrict b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

static void	bubble_sort(int *tab, size_t size)
{
	size_t	i;
	size_t	j;
	bool	swapped;

	i = 0;
	while (i < size - 1)
	{
		swapped = false;
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
				swapped = true;
			}
			j += 1;
		}
		if (!swapped)
		{
			return ;
		}
		i += 1;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	if (size < 2)
	{
		return ;
	}
	bubble_sort(tab, (size_t)size);
}

#ifdef TEST

// run with test main:
// clang ft_sort_int_tab.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	const int	expected1[] = {1, 2, 3};
	const int	expected2[] = {INT_MIN, -1, 0, INT_MAX};
	int			*test_case;

	test_case = (int []){3, 2, 1};
	ft_sort_int_tab(test_case, sizeof expected1 / sizeof(*expected1));
	assert(memcmp(test_case, expected1, sizeof expected1) == 0);
	test_case = (int []){INT_MAX, 0, -1, INT_MIN};
	ft_sort_int_tab(test_case, sizeof expected2 / sizeof(*expected2));
	assert(memcmp(test_case, expected2, sizeof expected2) == 0);
	puts("✅ All tests passed");
}

#endif
