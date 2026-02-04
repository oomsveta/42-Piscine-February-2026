/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:55:44 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/04 20:16:31 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

#include <stddef.h>	// provides size_t

static char	*ft_strcpy(char *restrict dest, const char *restrict src)
{
	const char	*d0 = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return ((char *)d0);
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

char	*ft_strcat(char *dest, char *src)
{
	ft_strcpy(dest + ft_strlen(dest), src);
	return (dest);
}

#ifdef TEST

// run with test main:
// clang ft_strcat.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char	dest[64];

	memset(dest, 'x', sizeof dest);
	strcpy(dest, "Hello");
	assert(ft_strcat(dest, " World") == dest);
	assert(strcmp(dest, "Hello World") == 0);
	memset(dest, 'x', sizeof dest);
	strcpy(dest, "boulangerie");
	assert(ft_strcat(dest, "") == dest);
	assert(strcmp(dest, "boulangerie") == 0);
	memset(dest, 'x', sizeof dest);
	strcpy(dest, "");
	assert(ft_strcat(dest, "Shrek") == dest);
	assert(strcmp(dest, "Shrek") == 0);
	memset(dest, 'x', sizeof dest);
	strcpy(dest, "");
	assert(ft_strcat(dest, "") == dest);
	assert(strcmp(dest, "") == 0);
	puts("✅ All tests passed");
}

#endif
