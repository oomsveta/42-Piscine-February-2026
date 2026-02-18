/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:47:58 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 13:25:38 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <limits.h>
# include <stdio.h>
#endif

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	if (length == 0)
	{
		return (1);
	}
	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
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
	const int	test4[] = {INT_MAX, 2, INT_MIN};
	const int	test5[] = {INT_MAX, INT_MIN};

	assert(ft_is_sort((int *)test1, 0, cmp));
	assert(ft_is_sort((int *)test2, 1, cmp));
	assert(ft_is_sort((int *)test3, 3, cmp));
	assert(!ft_is_sort((int *)test4, 3, cmp));
	assert(!ft_is_sort((int *)test5, 2, cmp));
	puts("✅ All tests passed");
}

#endif
