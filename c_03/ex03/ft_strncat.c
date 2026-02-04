/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:23:23 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/04 18:44:27 by lwicket          ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	const char	*d0 = dest;

	dest += ft_strlen(dest);
	while (n != 0 && *src != '\0')
	{
		*dest++ = *src++;
		n -= 1;
	}
	*dest = '\0';
	return ((char *)d0);
}

#ifdef TEST

// run with test main:
// clang ft_strncat.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char	dest[64];

	memset(dest, '\0', sizeof dest);
	strcpy(dest, "wow");
	assert(ft_strncat(dest, "ijbol", 0) == dest);
	assert(strcmp(dest, "wow") == 0);
	memset(dest, '\0', sizeof dest);
	strcpy(dest, "123");
	assert(ft_strncat(dest, "4567", 2) == dest);
	assert(strcmp(dest, "12345") == 0);
	memset(dest, '\0', sizeof dest);
	strcpy(dest, "Sonic");
	assert(ft_strncat(dest, "Hedgehog", 63) == dest);
	assert(strcmp(dest, "SonicHedgehog") == 0);
	memset(dest, '\0', sizeof dest);
	strcpy(dest, "Eggman");
	assert(ft_strncat(dest, "", 3) == dest);
	assert(strcmp(dest, "Eggman") == 0);
	memset(dest, '\0', sizeof dest);
	strcpy(dest, "");
	assert(ft_strncat(dest, "jpp", 1) == dest);
	assert(strcmp(dest, "j") == 0);
	puts("✅ All tests passed");
}

#endif
