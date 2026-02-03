/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 07:50:32 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/03 07:56:19 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

// What if a and b alias each other?

void	ft_ultimate_div_mod(int *a, int *b)
{
	const int	remainder = *a % *b;

	*a /= *b;
	*b = remainder;
}

#ifdef TEST

// run with test main:
// clang ft_ultimate_div_mod.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	int	a;
	int	b;

	a = 42;
	b = 19;
	ft_ultimate_div_mod(&a, &b);
	assert(a == 2 && b == 4);
	puts("✅ All tests passed");
}

#endif