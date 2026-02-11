/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:10:13 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/11 13:58:19 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>     // INT_MAX
#include <stdbool.h>	// provides bool, false

// could be an enum
#define SUCCESS 1
#define OVERFLOW_ERROR 2
#define UNDERFLOW_ERROR 3

static int	ft_isdigit(int c)
{
	return ((unsigned int)c - '0' < 10u);
}

static int	ft_isspace(int c)
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

int	parse_int(const char *nptr, int *result)
{
	bool				is_negative;
	unsigned int		acc;
	unsigned char		digit;
	const unsigned int	cutoff = ((unsigned int)INT_MAX + is_negative) / 10;
	const unsigned int	cutlim = ((unsigned int)INT_MAX + is_negative) % 10;

	is_negative = false;
	while (*nptr == '-' || *nptr == '+')
		is_negative ^= *nptr++ == '-';
	digit = (unsigned char)*nptr++ - '0';
	acc = 0;
	while (digit < 10u)
	{
		if (acc > cutoff || (acc == cutoff && digit > cutlim))
			return (OVERFLOW_ERROR + is_negative);
		acc = acc * 10 + digit;
		digit = (unsigned char)*nptr++ - '0';
	}
	if (is_negative)
		*result = -acc;
	else
		*result = +acc;
	return (SUCCESS);
}

int	ft_atoi(char *str)
{
	bool			is_negative;
	unsigned long	acc;

	str = ft_skip_spaces(str);
	is_negative = false;
	while (*str == '-' || *str == '+')
	{
		is_negative ^= *str == '-';
		str += 1;
	}
	acc = 0;
	while (ft_isdigit(*str))
	{
		acc = acc * 10 + *str - '0';
		str += 1;
	}
	if (is_negative)
	{
		return ((int)-acc);
	}
	return ((int)acc);
}
