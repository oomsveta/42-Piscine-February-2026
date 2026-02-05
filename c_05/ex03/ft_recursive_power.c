/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:05:30 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/05 17:11:02 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}

#ifdef TEST

// run with test main:
// clang ft_recursive_power.c -W{all,extra,error} -DTEST && ./a.out
int main(void)
{
	assert(ft_recursive_power(2, 9) == 512);
	assert(ft_recursive_power(-2, 31) == -2147483648);
	assert(ft_recursive_power(0, 0) == 1);
	assert(ft_recursive_power(0, 1) == 0);
	puts("✅ All tests passed");
}

#endif
