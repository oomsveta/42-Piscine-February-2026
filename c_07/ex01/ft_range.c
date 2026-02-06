/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:30:13 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/06 21:43:38 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

#include <stdlib.h>	// provides malloc, NULL, size_t

int	*ft_range(int min, int max)
{
	const size_t	size = max - min;
	size_t			i;
	int				*range;

	if (min >= max)
	{
		return (NULL);
	}
	range = malloc(sizeof(int [size]));
	if (!range)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		range[i] = min + i;
		i += 1;
	}
	return (range);
}

#ifdef TEST

// run with test main:
// clang ft_range.c -W{all,extra,error} -DTEST && ./a.out
int main(void)
{
	int	*range;

	assert(ft_range(42, 19) == NULL);
	assert(ft_range(42, 42) == NULL);
	range = ft_range(-3, 3);
	assert(memcmp(range, (int []){-3, -2, -1, 0, 1, 2}, sizeof(int [6])) == 0);
	free(range);
	puts("✅ All tests passed");
}

#endif
