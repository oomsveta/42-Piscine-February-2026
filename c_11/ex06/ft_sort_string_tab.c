/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:05:39 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 16:40:54 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1 += 1;
		s2 += 1;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	selection_sort(char *arr[], size_t size)
{
	size_t	i;
	size_t	j;
	size_t	index_of_min;

	i = 0;
	if (size < 2)
		return ;
	while (i < size - 1)
	{
		index_of_min = i;
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(arr[j], arr[index_of_min]) < 0)
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

void	ft_sort_string_tab(char *tab[])
{
	selection_sort(tab, get_element_count(tab));
}

/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		return (0);
	}
	ft_sort_string_tab(argv + 1);
	while (*argv)
	{
		puts(*argv);
		argv += 1;
	}
}
*/
