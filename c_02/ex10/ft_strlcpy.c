/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:55:15 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/04 10:16:22 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

#include <stddef.h>	// provides size_t

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len += 1;
	}
	return (len);
}

/**
 * @brief Copies a string from @p src to @p dest with a size limit.
 *
 * Copies the string @p src into @p dest, stopping when either the null
 * terminator of @p src is encountered or when @p size - 1 characters have been
 * copied. It always null-terminates @p dest, provided that @p size > 0.
 *
 * If the destination buffer is too small to hold the entire source string, 
 * truncation occurs. The function returns the length of @p src, which allows
 * the caller to detect truncation: truncation occurred if the return value is
 * greater than or equal to @p size.
 *
 * @see https://pubs.opengroup.org/onlinepubs/9799919799/functions/strlcpy.html
 *
 * @param dest Destination buffer.
 * @param src Source string.
 * @param size Size of the destination buffer.
 * @return Length of @p src. If it is >= @p size, truncation occurred.
 */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	size_t	i;

	if (size == 0)
	{
		return (ft_strlen(src));
	}
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (i + ft_strlen(&src[i]));
}

#ifdef TEST

// run with test main:
// clang ft_strlcpy.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char	buffer[64];

	memset(buffer, '\03', sizeof buffer);
	assert(ft_strlcpy(buffer, "Shrek", sizeof buffer) == 5);
	assert(memcmp(buffer, "Shrek", 6) == 0);
	memset(buffer, '\03', sizeof buffer);
	assert(ft_strlcpy(buffer, "pseudopseudohypoparathyroidism", 7) == 30);
	assert(memcmp(buffer, "pseudo", 7) == 0);
	memset(buffer, '\03', sizeof buffer);
	assert(ft_strlcpy(buffer, "xDD", 0) == 3);
	assert(memcmp(buffer, "\03", 1) == 0);
	memset(buffer, '\03', sizeof buffer);
	assert(ft_strlcpy(buffer, "Mario", 64) == 5);
	assert(memcmp(buffer, "Mario", 6) == 0);
	memset(buffer, '\03', sizeof buffer);
	assert(ft_strlcpy(buffer, "Xanto", 5) == 5);
	assert(memcmp(buffer, "Xant", 5) == 0);
	memset(buffer, '\03', sizeof buffer);
	assert(ft_strlcpy(buffer, "", 1) == 0);
	assert(memcmp(buffer, "", 1) == 0);
	puts("✅ All tests passed");
}

#endif
