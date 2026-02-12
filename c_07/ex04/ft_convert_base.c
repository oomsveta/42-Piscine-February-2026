/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:29:05 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 11:34:26 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>	// provides bool, false, true
#include <stddef.h>		// provides NULL, size_t
#include <limits.h>		// provides CHAR_BIT

char	*ft_skip_spaces(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strcpy(char *restrict dest, const char *restrict src);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);

static unsigned int	ft_abs(int n)
{
	if (n < 0)
	{
		return (-(unsigned int)n);
	}
	return (n);
}

static bool	is_valid_base(const char *base)
{
	if (base[0] == '\0' || base[1] == '\0')
	{
		return (false);
	}
	while (*base != '\0')
	{
		if (
			*base == '+'
			|| *base == '-'
			|| ft_strchr(base + 1, *base)
			|| *base == ' '
			|| (unsigned int)*base - '\t' < 5u
		)
		{
			return (false);
		}
		base += 1;
	}
	return (true);
}

static int	ft_atoi_base(const char *str, const char *digits)
{
	bool			is_negative;
	unsigned long	acc;
	const char		*digit_ptr;
	const size_t	radix = ft_strlen(digits);

	str = ft_skip_spaces(str);
	is_negative = false;
	while (*str == '-' || *str == '+')
	{
		is_negative ^= *str++ == '-';
	}
	acc = 0;
	digit_ptr = ft_strchr(digits, *str);
	while (digit_ptr != NULL && *digit_ptr != '\0')
	{
		acc = acc * radix + digit_ptr - digits;
		str += 1;
		digit_ptr = ft_strchr(digits, *str);
	}
	if (is_negative)
	{
		return ((int)-acc);
	}
	return ((int)acc);
}

static char	*ft_itoa_base(int n, char *digits, char *dst, size_t dst_len)
{
	unsigned int	acc;
	const size_t	radix = ft_strlen(digits);

	acc = ft_abs(n);
	dst = dst + dst_len - 1;
	*dst = '\0';
	while (acc >= radix)
	{
		*--dst = digits[acc % radix];
		acc /= radix;
	}
	*--dst = digits[acc % radix];
	if (n < 0)
	{
		*--dst = '-';
	}
	return (dst);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	buffer[sizeof(int) * CHAR_BIT + 2];
	int		value;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
	{
		return (NULL);
	}
	value = ft_atoi_base(nbr, base_from);
	return (ft_strdup(ft_itoa_base(value, base_to, buffer, sizeof buffer)));
}

/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// clang *.c -W{all,extra} -fsanitize=address,undefined && ./a.out
int	main(void)
{
	char	*test;

	test = ft_convert_base("1010", "01", "0123456789abcdef");
	assert(strcmp(test, "a") == 0);
	free(test);
	test = ft_convert_base(
		" \t\n\v\f\r+--+-++10000000000000000000000000000000", "01", "poneyvif");
	assert(strcmp(test, "-npppppppppp") == 0);
	free(test);
	puts("✅ All tests passed");
}
*/
