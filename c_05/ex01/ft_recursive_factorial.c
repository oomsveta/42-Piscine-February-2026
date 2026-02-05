/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:21:41 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/05 16:23:54 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	if (nb <= 1)
	{
		return (1);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}

#ifdef TEST

// run with test main:
// clang ft_recursive_factorial.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	assert(ft_recursive_factorial(-2147483648) == 0);
	assert(ft_recursive_factorial(-1) == 0);
	assert(ft_recursive_factorial(0) == 1);
	assert(ft_recursive_factorial(2) == 2);
	assert(ft_recursive_factorial(3) == 6);
	assert(ft_recursive_factorial(4) == 24);
	assert(ft_recursive_factorial(5) == 120);
	assert(ft_recursive_factorial(6) == 720);
	assert(ft_recursive_factorial(7) == 5040);
	assert(ft_recursive_factorial(8) == 40320);
	assert(ft_recursive_factorial(9) == 362880);
	assert(ft_recursive_factorial(10) == 3628800);
	assert(ft_recursive_factorial(11) == 39916800);
	assert(ft_recursive_factorial(12) == 479001600);
	puts("✅ All tests passed");
}

#endif
