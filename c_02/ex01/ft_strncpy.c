/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:46:28 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/03 17:35:18 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	const char	*d0 = dest;

	while (n != 0 && *src != '\0')
	{
		*dest++ = *src++;
		n -= 1;
	}
	while (n != 0)
	{
		*dest++ = '\0';
		n -= 1;
	}
	return ((char *)d0);
}

#ifdef TEST

// run with test main:
// clang ft_strncpy.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char	dest[16];

	assert(ft_strncpy(dest, "Shrek", 6) == dest);
	assert(memcmp(dest, "Shrek", 6) == 0);
	assert(ft_strncpy(dest, "Morshu", 3) == dest);
	assert(memcmp(dest, "More", 4) == 0);
	assert(ft_strncpy(dest, "hey", 16) == dest);
	assert(memcmp(dest, "hey\0\0\0\0\0\0\0\0\0\0\0\0", 16) == 0);
	assert(ft_strncpy(dest, "Xanto\0hidden", 12) == dest);
	assert(memcmp(dest, "Xanto\0\0\0\0\0\0\0\0\0\0\0\0", 12) == 0);
	puts("✅ All tests passed");
}

#endif
