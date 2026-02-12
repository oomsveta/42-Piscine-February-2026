/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:53:18 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 18:20:10 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

static int	ft_isupper(int c)
{
	return ((unsigned)c - 'A' < 26u);
}

int	ft_str_is_uppercase(char *str)
{
	while (ft_isupper(*str))
	{
		str += 1;
	}
	return (*str == '\0');
}

#ifdef TEST

// run with test main:
// clang ft_str_is_uppercase.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char	str[2];

	assert(ft_str_is_uppercase("") == 1);
	assert(ft_str_is_uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 1);
	str[0] = 0x01;
	str[1] = '\0';
	while (str[0] < 'A')
	{
		assert(ft_str_is_uppercase(str) == 0);
		str[0] += 1;
	}
	str[0] = 'Z' + 1;
	while (str[0] < 0x7f)
	{
		assert(ft_str_is_uppercase(str) == 0);
		str[0] += 1;
	}
	assert(ft_str_is_uppercase(str) == 0);
	assert(ft_str_is_uppercase("abcA") == 0);
	puts("✅ All tests passed");
}

#endif
