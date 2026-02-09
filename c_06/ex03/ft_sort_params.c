/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 08:59:57 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/09 09:38:13 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides EXIT_SUCCESS
#include <unistd.h>	// provides STDOUT_FILENO, write

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

static void	ft_puts(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len += 1;
	}
	write(STDOUT_FILENO, s, len);
	write(STDOUT_FILENO, "\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		return (EXIT_SUCCESS);
	}
	selection_sort(argv + 1, argc - 1);
	while (*++argv != NULL)
	{
		ft_puts(*argv);
	}
}
