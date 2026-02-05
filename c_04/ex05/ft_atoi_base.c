/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:56:56 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/05 16:09:31 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>	// provides bool, false, true
#include <stddef.h>		// provides size_t

static int	ft_isspace(int c)
{
	return (c == ' ' || (unsigned int)c - '\t' < 5u);
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

int	ft_atoi_base(char *str, char *base)
{
	const size_t	radix = ft_strlen(base);
	bool			is_negative;
	unsigned long	acc;
	const char		*digit_ptr;

	if (!is_valid_base(base))
		return (0);
	while (ft_isspace(*str))
		str += 1;
	is_negative = false;
	while (*str == '-' || *str == '+')
		is_negative ^= *str++ == '-';
	acc = 0;
	digit_ptr = ft_strchr(base, *str);
	while (digit_ptr != NULL && *digit_ptr != '\0')
	{
		acc = acc * radix + digit_ptr - base;
		digit_ptr = ft_strchr(base, *str);
		str += 1;
	}
	if (is_negative)
		return ((int)-acc);
	return ((int)acc);
}

/*
#include <assert.h>
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	assert(
		ft_atoi_base(
			" \t\n\v\f\r+--+-++10000000000000000000000000000000234", "01"
		) == INT_MIN
	);
	assert(ft_atoi_base("1010", "101") == 0);
	assert(ft_atoi_base("", "01") == 0);
	puts("LGTM :)");
}
*/
