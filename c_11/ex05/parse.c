/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:10:13 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 13:41:43 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>     // INT_MAX
#include <stdbool.h>	// provides bool, false

// could be an enum
#define SUCCESS 1
#define OVERFLOW_ERROR 2
#define UNDERFLOW_ERROR 3

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
	bool			is_negative;
	unsigned int	acc;
	unsigned char	digit;
	unsigned int	cutoff;
	unsigned int	cutlim;

	nptr = ft_skip_spaces(nptr);
	is_negative = false;
	while (*nptr == '-' || *nptr == '+')
		is_negative ^= *nptr++ == '-';
	cutoff = ((unsigned int)INT_MAX + is_negative) / 10;
	cutlim = ((unsigned int)INT_MAX + is_negative) % 10;
	digit = (unsigned char)*nptr++ - '0';
	acc = 0;
	while (digit < 10u)
	{
		if (acc > cutoff || (acc == cutoff && digit > cutlim))
			return (OVERFLOW_ERROR + is_negative);
		acc = acc * 10 + digit;
		digit = (unsigned char)*nptr++ - '0';
	}
	*result = (int []){+acc, -acc}[is_negative];
	return (SUCCESS);
}
