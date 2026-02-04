/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:12:40 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/04 22:12:46 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>	// provides CHAR_BIT
#include <unistd.h>	// provides STDOUT_FILENO, write

static unsigned int	ft_abs(int n)
{
	if (n < 0)
	{
		return (-(unsigned int)n);
	}
	return (n);
}

void	ft_putnbr(int n)
{
	unsigned int	acc;
	char			buffer[(sizeof(int) * CHAR_BIT - 1) * 28 / 93 + 2];
	char			*ptr;

	ptr = buffer + sizeof buffer;
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
