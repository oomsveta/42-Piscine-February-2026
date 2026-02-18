/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:10:13 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 23:12:47 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>	// provides bool, false

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

int	ft_atoi(const char *nptr)
{
	bool			is_negative;
	unsigned int	acc;

	nptr = ft_skip_spaces(nptr);
	is_negative = false;
	while (*nptr == '-' || *nptr == '+')
	{
		is_negative ^= *nptr++ == '-';
	}
	acc = 0;
	while (ft_isdigit(*nptr))
	{
		acc = acc * 10 + *nptr++ - '0';
	}
	if (is_negative)
	{
		return ((int)-acc);
	}
	return ((int)acc);
}
