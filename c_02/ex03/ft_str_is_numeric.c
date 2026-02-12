/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:43:34 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 18:20:07 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

static int	ft_isdigit(int c)
{
	return ((unsigned int)c - '0' < 10u);
}

int	ft_str_is_numeric(char *str)
{
	while (ft_isdigit(*str))
	{
		str += 1;
	}
	return (*str == '\0');
}

#ifdef TEST

// run with test main:
// clang ft_str_is_numeric.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char	str[2];

	assert(ft_str_is_numeric("") == 1);
	assert(ft_str_is_numeric("0123456789") == 1);
	str[0] = 0x01;
	str[1] = '\0';
	while (str[0] < '0')
	{
		assert(ft_str_is_numeric(str) == 0);
		str[0] += 1;
	}
	str[0] = '9' + 1;
	while (str[0] < 0x7f)
	{
		assert(ft_str_is_numeric(str) == 0);
		str[0] += 1;
	}
	assert(ft_str_is_numeric(str) == 0);
	assert(ft_str_is_numeric("123A") == 0);
	puts("✅ All tests passed");
}

#endif
