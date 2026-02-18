/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:22:34 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 14:00:18 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <stdio.h>
# include <string.h>
#endif

#include <stddef.h>

static void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	selection_sort(char *arr[], size_t size, int (*cmp)(char *, char *))
{
	size_t	i;
	size_t	j;
	size_t	index_of_min;

	if (size < 2)
		return ;
	i = 0;
	while (i < size - 1)
	{
		index_of_min = i;
		j = i + 1;
		while (j < size)
		{
			if (cmp(arr[j], arr[index_of_min]) < 0)
			{
				index_of_min = j;
			}
			j += 1;
		}
		if (index_of_min != i)
		{
			ft_swap(&arr[i], &arr[index_of_min]);
		}
		i += 1;
	}
}

/**
 * Computes the number of elements of a NULL-terminated array of strings.
 */
static size_t	get_element_count(char *arr[])
{
	size_t	nbr_of_elements;

	nbr_of_elements = 0;
	while (arr[nbr_of_elements] != NULL)
	{
		nbr_of_elements += 1;
	}
	return (nbr_of_elements);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	selection_sort(tab, get_element_count(tab), cmp);
}

#ifdef TEST

// run with test main:
// clang ft_advanced_sort_string_tab.c -DTEST -W{all,extra} && ./a.out
int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		return (0);
	}
	ft_advanced_sort_string_tab(argv + 1, (int (*)(char *, char *))strcmp);
	while (*argv)
	{
		puts(*argv);
		argv += 1;
	}
}

#endif
