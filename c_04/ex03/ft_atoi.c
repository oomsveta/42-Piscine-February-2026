/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:14:03 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/09 17:00:15 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

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

#ifdef TEST

// run with test main:
// clang ft_atoi.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	assert(ft_atoi("513") == 513);
	assert(ft_atoi("+2") == 2);
	assert(ft_atoi("-+2") == -2);
	assert(ft_atoi(" \t\n\v\f\r--++++--2147483647Lol") == 2147483647);
	assert(ft_atoi("- 1") == 0);
	assert(ft_atoi("-1-") == -1);
	assert(ft_atoi("a123") == 0);
	assert(ft_atoi("---2147483648") == -2147483648);
	assert(ft_atoi("") == 0);
	assert(ft_atoi("0") == 0);
	assert(ft_atoi("\x08") == 0);
	assert(ft_atoi("007") == 7);
	puts("✅ All tests passed");
}

#endif
