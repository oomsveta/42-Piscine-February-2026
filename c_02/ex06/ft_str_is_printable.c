/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:55:43 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/03 18:59:50 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

static int	ft_isprint(int c)
{
	return ((unsigned int)c - ' ' < 95u);
}

int	ft_str_is_printable(char *str)
{
	while (ft_isprint(*str))
	{
		str += 1;
	}
	return (*str == '\0');
}

#ifdef TEST

// run with test main:
// clang ft_str_is_printable.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char	str[2];

	assert(ft_str_is_printable("") == 1);
	str[0] = 0x01;
	str[1] = '\0';
	while (str[0] < ' ')
	{
		assert(ft_str_is_printable(str) == 0);
		str[0] += 1;
	}
	while (str[0] < 0x7f)
	{
		assert(ft_str_is_printable(str) == 1);
		str[0] += 1;
	}
	assert(ft_str_is_printable(str) == 0);
	assert(ft_str_is_printable("abcA\n") == 0);
	puts("✅ All tests passed");
}

#endif
