/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:34:38 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/05 18:27:46 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

char	*ft_strcpy(char *dest, char *src)
{
	const char	*d0 = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return ((char *)d0);
}

#ifdef TEST

// run with test main:
// clang ft_strcpy.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	const char	src1[] = "";
	const char	src2[] = "shrek";
	char		dest1[16];
	char		dest2[16];

	dest1[0] = 42;
	assert(ft_strcpy(dest1, (char *)src1) == dest1);
	assert(memcmp(dest1, "", sizeof src1) == 0);
	assert(ft_strcpy(dest2, (char *)src2) == dest2);
	assert(memcmp(dest2, "shrek", sizeof src2) == 0);
	puts("✅ All tests passed");
}

#endif
