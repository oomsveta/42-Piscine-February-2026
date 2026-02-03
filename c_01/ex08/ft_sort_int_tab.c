/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:07:24 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/03 10:19:20 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>		// provides size_t
#include <stdbool.h>	// provides bool, false, true

static void	ft_swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

static void	bubble_sort(int *tab, size_t size)
{
	size_t	i;
	size_t	j;
	bool	sorted;

	i = size - 1;
	while (i >= 1)
	{
		j = 0;
		sorted = true;
		while (j < i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
				sorted = false;
			}
			j += 1;
		}
		if (sorted)
		{
			return ;
		}
		i -= 1;
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
