/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:01:00 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/04 20:09:36 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

#include <stddef.h>	// provides size_t

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

static size_t	ft_strnlen(const char *str, size_t n)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && len < n)
	{
		len += 1;
	}
	return (len);
}

static size_t	ft_strlcpy(
	char *restrict dest, const char *restrict src, size_t size
)
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

/**
 * @brief Concatenates the string src to dest with a size limit.
 *
 * Appends src to dest, ensuring that the total length does not exceed size - 1.
 * Null termination is guaranteed provided that there is space to append at
 * least one character (i.e., size > strlen(dest)).
 * 
 * The function returns the total length of the string it tried to create. If
 * the return value is greater than or equal to size, truncation occurred,
 * meaning not all of src was appended.
 *
 * @see https://pubs.opengroup.org/onlinepubs/9799919799/functions/strlcat.html
 *
 * @param dest Destination buffer where src will be appended.
 * @param src Source string to append to dest.
 * @param size Size of dest, including the null terminator.
 * @return The total length of the string it attempted to create
 *		   (strlen(src) + min(size, strlen(initial dest))).
 *         If the return value is >= size, truncation occurred.
 */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	size_t	dst_len;

	dst_len = ft_strnlen(dest, size);
	if (dst_len == size)
	{
		return (size + ft_strlen(src));
	}
	return (dst_len + ft_strlcpy(dest + dst_len, src, size - dst_len));
}

#ifdef TEST

// run with test main:
// clang ft_strlcat.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char	buffer[64];

	memset(buffer, 'x', sizeof buffer);
	strcpy(buffer, "stoemp");
	assert(ft_strlcat(buffer, "gabon", 12) == 11);
	assert(memcmp(buffer, "stoempgabon", 12) == 0);
	memset(buffer, 'x', sizeof buffer);
	strcpy(buffer, "Gargamel");
	assert(ft_strlcat(buffer, "heyy", 3) == 7);
	assert(memcmp(buffer, "Gargamel", 9) == 0);
	memset(buffer, 'x', sizeof buffer);
	strcpy(buffer, "gamelon");
	assert(ft_strlcat(buffer, "yo", 7) == 9);
	assert(memcmp(buffer, "gamelon", 8) == 0);
	memset(buffer, 'x', sizeof buffer);
	strcpy(buffer, "swamped");
	assert(ft_strlcat(buffer, "aspirateur", 9) == 17);
	assert(memcmp(buffer, "swampeda", 9) == 0);
	memset(buffer, 'x', sizeof buffer);
	strcpy(buffer, "");
	assert(ft_strlcat(buffer, "gaufre", sizeof buffer) == 6);
	assert(memcmp(buffer, "gaufre", 7) == 0);
	puts("✅ All tests passed");
}

#endif
