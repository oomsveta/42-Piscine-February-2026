/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:36:25 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/03 18:38:10 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

static int	ft_isalpha(int c)
{
	return (((unsigned int)c | 0x20) - 'a' < 26u);
}

int	ft_str_is_alpha(char *str)
{
	while (ft_isalpha(*str))
	{
		str += 1;
	}
	return (*str == '\0');
}

#ifdef TEST

// run with test main:
// clang ft_str_is_alpha.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char	str[2];

	assert(ft_str_is_alpha("") == 1);
	assert(ft_str_is_alpha(
			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == 1);
	str[0] = 0x01;
	str[1] = '\0';
	while (str[0] < 'A')
	{
		assert(ft_str_is_alpha(str) == 0);
		str[0] += 1;
	}
	str[0] = 'z' + 1;
	while (str[0] < 0x7f)
	{
		assert(ft_str_is_alpha(str) == 0);
		str[0] += 1;
	}
	assert(ft_str_is_alpha(str) == 0);
	assert(ft_str_is_alpha("six7") == 0);
	puts("✅ All tests passed");
}

#endif