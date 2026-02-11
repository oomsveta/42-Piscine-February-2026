/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 09:35:20 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/11 13:58:53 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

static unsigned int	ft_abs(int n)
{
	if (n < 0)
	{
		return (-(unsigned int)n);
	}
	return (n);
}

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

void	ft_puts(const char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "\n", 1);
}

void	ft_putnbr(int n)
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
