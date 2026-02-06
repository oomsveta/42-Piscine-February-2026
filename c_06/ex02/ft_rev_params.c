/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 08:41:13 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/06 09:01:39 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides size_t, STDOUT_FILENO, write

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
	while (argc > 1)
	{
		ft_puts(argv[argc - 1]);
		argc -= 1;
	}
}
