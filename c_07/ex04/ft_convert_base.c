/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:29:05 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/06 22:54:33 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>	// provides bool, false, true
#include <stdlib.h>
#include <limits.h>

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

static int  ft_isspace(int c)
{
	return (c == ' ' || (unsigned int)c - '\t' < 5u);
}

static char	*ft_skip_spaces(const char *str)
{
	while (ft_isspace(*str))
	{
		str += 1;
	}
	return ((char *)str);
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	bool	is_negative;
	char	buffer[sizeof(int) * CHAR_BIT + 2];
	char	*ptr;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
	{
		return (NULL);
	}
	nbr = ft_skip_spaces(nbr);
	is_negative = false;
	while (*nbr == '-' || *nbr == '+')
	{
		is_negative ^= *nbr++ == '-';
	}
	ptr = buffer;
	*ptr-- = '\0';
}
