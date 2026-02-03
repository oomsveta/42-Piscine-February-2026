/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:38:50 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/03 09:47:29 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

#include <stddef.h>	// provides size_t

int	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len += 1;
	}
	return ((int)len);
}

#ifdef TEST

// run with test main:
// clang ft_strlen.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	assert(ft_strlen("") == 0);
	assert(ft_strlen("shrek") == 5);
	puts("✅ All tests passed");
}

#endif
