/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 08:32:50 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/06 08:58:24 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides EXIT_SUCCESS, size_t
#include <unistd.h>	// provides STDOUT_FILENO, write

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

static void	ft_puts(const char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		return (EXIT_SUCCESS);
	}
	while (*++argv != NULL)
	{
		ft_puts(*argv);
	}
}
