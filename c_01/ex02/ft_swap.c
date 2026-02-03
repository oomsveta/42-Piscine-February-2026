/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 23:22:02 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/03 09:35:04 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

void	ft_swap(int *a, int *b)
{
	const int	tmp = *a;

	*a = *b;
	*b = tmp;
}

#ifdef TEST

// run with test main:
// clang ft_swap.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	int	a;
	int	b;

	a = 'A';
	b = 'B';
	ft_swap(&a, &b);
	assert(a == 'B' && b == 'A');
	a = 'A';
	ft_swap(&a, &a);
	assert(a == a);
	puts("✅ All tests passed");
}

#endif
