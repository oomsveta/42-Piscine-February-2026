/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:32:12 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/04 23:35:46 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>		// provides CHAR_BIT
#include <stdbool.h>	// provides bool, false, true
#include <unistd.h>		// provides NULL, size_t, STDOUT_FILENO, write

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

static char	*ft_strchr(const char *str, int c)
{
	c = (unsigned char)c;
	while (true)
	{
		if ((unsigned char)*str == c)
		{
			return ((char *)str);
		}
		if (*str == '\0')
		{
			return (NULL);
		}
		str += 1;
	}
}

static bool	is_valid_base(const char *base)
{
	if (base[0] == '\0' || base[1] == '\0')
	{
		return (false);
	}
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-' || ft_strchr(base + 1, *base))
		{
			return (false);
		}
		base += 1;
	}
	return (true);
}

void	ft_putnbr_base(int nbr, char *base)
{
	const size_t	radix = ft_strlen(base);
	unsigned int	acc;
	char			buffer[sizeof(int) * CHAR_BIT + 1];
	char			*ptr;

	if (!is_valid_base(base))
	{
		return ;
	}
	acc = ft_abs(nbr);
	ptr = buffer + sizeof buffer - 1;
	while (acc >= radix)
	{
		*ptr-- = base[acc % radix];
		acc /= radix;
	}
	*ptr = base[acc % radix];
	if (nbr < 0)
	{
		*--ptr = '-';
	}
	write(STDOUT_FILENO, ptr, buffer + sizeof buffer - ptr);
}
