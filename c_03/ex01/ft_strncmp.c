/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:50:19 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/04 16:54:59 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
	{
		return (0);
	}
	n -= 1;
	while (*s1 == *s2 && *s1 != '\0' && n != 0)
	{
		s1 += 1;
		s2 += 1;
		n -= 1;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

#ifdef TEST

// run with test main:
// clang ft_strncmp.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	assert(ft_strncmp("A", "Z", 0) == 0);
	assert(ft_strncmp("\xFF", "\x80", 1) > 0);
	assert(ft_strncmp("", "", 1) == 0);
	assert(ft_strncmp("Donkey Kong", "Donkey Kong", 99999999) == 0);
	assert(ft_strncmp("Super Mario Galaxy", "Super Mario Sunshine", 12) == 0);
	puts("✅ All tests passed");
}

#endif
