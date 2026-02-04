/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:50:55 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/04 09:53:37 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>
#endif

static int	ft_isupper(int c)
{
	return ((unsigned int)c - 'A' < 26u);
}

static int	ft_tolower(int c)
{
	if (ft_isupper(c))
	{
		return (c | 0x20);
	}
	return (c);
}

char	*ft_strlowcase(char *str)
{
	const char	*s0 = str;

	while (*str != '\0')
	{
		*str = ft_tolower(*str);
		str += 1;
	}
	return ((char *)s0);
}

#ifdef TEST

// run with test main:
// clang ft_strlowcase.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char			test_str[32];
	unsigned int	i;

	strcpy(test_str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	assert(ft_strlowcase(test_str) == test_str);
	assert(strcmp(test_str, "abcdefghijklmnopqrstuvwxyz") == 0);
	test_str[1] = '\0';
	i = 0;
	while (i <= 127)
	{
		if (isupper(i))
		{
			i += 1;
			continue ;
		}
		test_str[0] = i;
		assert(*ft_strlowcase(test_str) == (char)i);
		i += 1;
	}
	puts("✅ All tests passed");
}

#endif
