/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:36:25 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/03 17:51:14 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

static int	ft_isalpha(int c)
{
	return ((unsigned int)(c | 0x20) - 'a' < 26u);
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
	assert(ft_isalpha("") == 1);
	assert(ft_isalpha("") == 1);
	puts("✅ All tests passed");
}

#endif