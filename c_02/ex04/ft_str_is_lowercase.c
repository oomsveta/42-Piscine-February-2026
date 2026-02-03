/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:49:33 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/03 18:51:52 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

static int	ft_islower(int c)
{
	return ((unsigned int)c - 'a' < 26u);
}

int	ft_str_is_lowercase(char *str)
{
	while (ft_islower(*str))
	{
		str += 1;
	}
	return (*str == '\0');
}

#ifdef TEST

// run with test main:
// clang ft_str_is_lowercase.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char	str[2];

	assert(ft_str_is_lowercase("") == 1);
	assert(ft_str_is_lowercase("abcdefghijklmnopqrstuvwxyz") == 1);
	str[0] = 0x01;
	str[1] = '\0';
	while (str[0] < 'a')
	{
		assert(ft_str_is_lowercase(str) == 0);
		str[0] += 1;
	}
	str[0] = 'z' + 1;
	while (str[0] < 0x7f)
	{
		assert(ft_str_is_lowercase(str) == 0);
		str[0] += 1;
	}
	assert(ft_str_is_lowercase(str) == 0);
	assert(ft_str_is_lowercase("abcA") == 0);
	puts("✅ All tests passed");
}

#endif