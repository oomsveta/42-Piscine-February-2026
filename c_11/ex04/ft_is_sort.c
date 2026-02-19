/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:47:58 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/19 10:03:58 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <limits.h>
# include <stdio.h>
#endif

#include <stdbool.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	bool	is_ascending;
	bool	is_descending;
	int		i;
	int		diff;

	if (length == 0)
	{
		return (1);
	}
	i = 0;
	is_ascending = false;
	is_descending = false;
	while (i < length - 1)
	{
		diff = f(tab[i], tab[i + 1]);
		is_ascending |= diff < 0;
		is_descending |= diff > 0;
		if (is_ascending && is_descending)
		{
			return (0);
		}
		i += 1;
	}
	return (1);
}

#ifdef TEST

int	cmp(int a, int b)
{
	if (a < b)
	{
		return (-1);
	}
	return (a != b);
}

// clang ft_is_sort.c -W{all,extra} -DTEST && ./a.out 
int	main(void)
{
	const int	test1[] = {};
	const int	test2[] = {1};
	const int	test3[] = {INT_MIN, 0, INT_MAX};
	const int	test4[] = {INT_MAX, INT_MAX, 2, INT_MIN};
	const int	test5[] = {
		7, 7, 7, 7, 6, 6, 6, 6, 5, 5, 4, 3, 3,
		3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1
	};

	assert(ft_is_sort((int *)test1, 0, cmp));
	assert(ft_is_sort((int *)test2, 1, cmp));
	assert(ft_is_sort((int *)test3, 3, cmp));
	assert(ft_is_sort((int *)test4, 4, cmp));
	assert(ft_is_sort((int *)test5, sizeof test5 / sizeof(int), cmp));
	assert(!ft_is_sort((int []){2, 3, 1}, 3, cmp));
	assert(ft_is_sort((int []){3, 2}, 3, cmp));
	puts("✅ All tests passed");
}

#endif
