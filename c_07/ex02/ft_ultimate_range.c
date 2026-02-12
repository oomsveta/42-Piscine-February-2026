/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:37:17 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 10:39:44 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

#include <stdlib.h>	// provides malloc, NULL, size_t

int	ft_ultimate_range(int **range, int min, int max)
{
	const size_t	size = max - min;
	size_t			i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int [size]));
	if (!range)
	{
		return (-1);
	}
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i += 1;
	}
	return (size);
}

#ifdef TEST

// run with test main:
// clang ft_ultimate_range.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	int	*range;

	assert(ft_ultimate_range(&range, 42, 19) == 0);
	assert(range == NULL);
	assert(ft_ultimate_range(&range, 42, 42) == 0);
	assert(range == NULL);
	assert(ft_ultimate_range(&range, -3, 3) == 6);
	assert(memcmp(range, (int []){-3, -2, -1, 0, 1, 2}, sizeof(int [6])) == 0);
	free(range);
	puts("✅ All tests passed");
}

#endif
