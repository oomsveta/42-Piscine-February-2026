/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:01:47 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 13:12:26 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

#include <stddef.h>	// provides NULL

int	ft_any(char *tab[], int (*f)(char*))
{
	while (*tab != NULL)
	{
		if (f(*tab))
		{
			return (1);
		}
		tab += 1;
	}
	return (0);
}

#ifdef TEST

static int	ft_isdigit(int c)
{
	return ((unsigned int)c - '0' < 10u);
}

static int	ft_str_is_numeric(char *str)
{
	while (ft_isdigit(*str))
	{
		str += 1;
	}
	return (*str == '\0');
}

// clang ft_any.c -W{all,extra} -DTEST && ./a.out 
int	main(void)
{
	const char	*test1[] = {"a", "b", "c", NULL};
	const char	*test2[] = {"1", "2", "3", NULL};
	const char	*test3[] = {"a", "b", "3", NULL};

	assert(!ft_any((char **)test1, ft_str_is_numeric));
	assert(ft_any((char **)test2, ft_str_is_numeric));
	assert(ft_any((char **)test3, ft_str_is_numeric));
	puts("✅ All tests passed");
}

#endif
