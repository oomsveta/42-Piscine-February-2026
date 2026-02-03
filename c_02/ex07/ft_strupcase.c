/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:01:47 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/03 22:26:24 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>
#endif

static int	ft_islower(int c)
{
	return ((unsigned int)c - 'a' < 26u);
}

static int	ft_toupper(int c)
{
	if (ft_islower(c))
	{
		return (c ^ 0x20);
	}
	return (c);
}

char	*ft_strupcase(char *str)
{
	const char	*s0 = str;

	while (*str != '\0')
	{
		*str = ft_toupper(*str);
		str += 1;
	}
	return ((char *)s0);
}

#ifdef TEST

// run with test main:
// clang ft_strupcase.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char			test_str[32];
	unsigned int	i;

	strcpy(test_str, "abcdefghijklmnopqrstuvwxyz");
	assert(ft_strupcase(test_str) == test_str);
	assert(strcmp(test_str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0);
	test_str[1] = '\0';
	i = 0;
	while (i <= 127)
	{
		if (islower(i))
		{
			i += 1;
			continue ;
		}
		test_str[0] = i;
		assert(*ft_strupcase(test_str) == (char)i);
		i += 1;
	}
	puts("✅ All tests passed");
}

#endif
