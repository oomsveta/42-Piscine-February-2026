/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 10:32:23 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/08 11:12:21 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides free, malloc, size_t

// TODO: no typedefs in .c files
typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len += 1;
	}
	return (len);
}

static void	*ft_memdup(const void *buffer, size_t n)
{
	const unsigned char	*bytes = (const unsigned char *)buffer;
	unsigned char		*dup;
	size_t				i;

	dup = malloc(n);
	if (!dup)
	{
		return (NULL);
	}
	while (i < n)
	{
		dup[i] = bytes[i];
	}
	return ((void *)dup);
}

static void	free_all(t_stock_str **to_free, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(to_free[i]->copy);
		to_free[i]->copy = NULL;
		i += 1;
	}
	free(*to_free);
	*to_free = NULL;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*strings;
	t_stock_str	string;
	size_t		i;

	strings = malloc(sizeof(t_stock_str [ac + 1]));
	if (!strings)
	{
		return (NULL);
	}
	strings[ac] = (t_stock_str){0};
	i = 0;
	while (i < ac)
	{
		string = (t_stock_str){.size = ft_strlen(av[i]), .str = av[i]};
		string.copy = ft_memdup(string.str, string.size + 1);
		if (!string.copy && i > 0)
		{
			free_all(&strings, i - 1);
			return (NULL);
		}
		string.copy[string.size] = '\0';
		strings[i] = string;
		i += 1;
	}
	return (strings);
}
