/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:43:28 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/06 23:27:25 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1 += 1;
		s2 += 1;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

#ifdef TEST

// run with test main:
// clang ft_strcmp.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	assert(ft_strcmp("", "") == 0);
	assert(ft_strcmp("Xipe Totec", "Xipe Totec") == 0);
	assert(ft_strcmp("Morshu", "") > 0);
	assert(ft_strcmp("\x80", "Zorglub") > 0);
	assert(ft_strcmp("AAAAAAAA", "AAAAAAA") > 0);
	assert(ft_strcmp("", "Gwonam") < 0);
	assert(ft_strcmp("Roblox", "\xFF") < 0);
	assert(ft_strcmp("AAAAAAA", "AAAAAAAA") < 0);
	puts("✅ All tests passed");
}

#endif
