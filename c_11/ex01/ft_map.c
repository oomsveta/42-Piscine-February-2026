/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:43:55 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/10 19:01:03 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <stdio.h>
#endif

#include <stdlib.h>	// provides malloc, NULL

int	*ft_map(int tab[], int length, int (*f)(int))
{
	int	*mapped;
	int	i;

	mapped = malloc(sizeof(int [length]));
	if (!mapped)
	{
		return (NULL);
	}
	i = 0;
	while (i < length)
	{
		mapped[i] = f(tab[i]);
		i += 1;
	}
	return (mapped);
}

#ifdef TEST

static int	twice(int n)
{
	return (n * 2);
}

static void	print_int_array(int *arr, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		printf("%d, ", arr[i]);
		i += 1;
	}
}

// clang ft_map.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	const int		numbers[] = {1, 2, 3, 4, 5};
	const size_t	length = sizeof numbers / sizeof(*numbers);
	int				*mapped;

	mapped = ft_map((int *)numbers, length, twice);
	if (!mapped)
	{
		return (EXIT_FAILURE);
	}
	print_int_array((int *)mapped, length);
	puts("");
	free(mapped);
}

#endif
