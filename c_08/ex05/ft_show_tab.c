/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:08:38 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/08 12:36:55 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>			// provides CHAR_BIT
#include <stdio.h>			// provides EOF
#include <unistd.h>			// provides ssize_t, STDOUT_FILENO, write
#include "ft_stock_str.h"	// provides s_stock_str

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

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

static unsigned int	ft_abs(int n)
{
	if (n < 0)
	{
		return (-(unsigned int)n);
	}
	return (n);
}

static void	ft_putnbr(int n)
{
	unsigned int	acc;
	char			buffer[(sizeof(int) * CHAR_BIT - 1) * 28 / 93 + 3];
	char			*ptr;

	ptr = buffer + sizeof buffer;
	*--ptr = '\n';
	acc = ft_abs(n);
	while (acc >= 10)
	{
		*--ptr = acc % 10 | '0';
		acc /= 10;
	}
	*--ptr = acc % 10 | '0';
	if (n < 0)
	{
		*--ptr = '-';
	}
	write(STDOUT_FILENO, ptr, buffer + sizeof buffer - ptr);
}

static int ft_puts(const char *s)
{
	ssize_t	bytes_written;

	bytes_written = write(STDOUT_FILENO, s, ft_strlen(s));
	if (bytes_written == -1)
	{
		return (EOF);
	}
	if (write(STDOUT_FILENO, "\n", 1) == -1)
	{
		return (EOF);
	}
	return (bytes_written + 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != 0)
	{
		write(STDOUT_FILENO, par->str, par->size);
		write(STDOUT_FILENO, "\n", 1);
		ft_putnbr(par->size);
		ft_puts(par->copy);
		par += 1;
	}
}

/* #include <stdio.h>
#include <stdlib.h>

// clang ft_show_tab.c ../ex04/ft_strs_to_tab.c -W{all,extra,error} && ./a.out
int	main(int argc, char *argv[])
{
	t_stock_str	*strings;
	size_t		i;
	
	strings = ft_strs_to_tab(argc, argv);
	if (!strings)
	{
		perror("failed to create strings");
		return (1);
	}
	ft_show_tab(strings);
	i = 0;
	while (strings[i].str)
	{
		free(strings[i].copy);
		i += 1;
	}
	free(strings);
} */
