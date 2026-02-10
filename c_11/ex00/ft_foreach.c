/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:34:25 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/10 18:58:23 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <limits.h>
# include <unistd.h>
#endif

void	ft_foreach(int tab[], int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i += 1;
	}
}

#ifdef TEST

static unsigned int	ft_abs(int n)
{
	if (n < 0)
	{
		return (-(unsigned int)n);
	}
	return (n);
}

static void	ft_putnbr(int n)
{
	unsigned int	acc;
	char			buffer[(sizeof(int) * CHAR_BIT - 1) * 28 / 93 + 3];
	char			*ptr;

	ptr = buffer + sizeof buffer;
	*--ptr = '\n';
	acc = ft_abs(n);
	while (acc >= 10)
	{
		*--ptr = acc % 10 | '0';
		acc /= 10;
	}
	*--ptr = acc % 10 | '0';
	if (n < 0)
	{
		*--ptr = '-';
	}
	write(STDOUT_FILENO, ptr, buffer + sizeof buffer - ptr);
}

// clang ft_foreach.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	const int	primes[] = {2, 5, 7, 11, 13, 17, 19};

	ft_foreach((int *)primes, sizeof primes / sizeof(*primes), ft_putnbr);
}

#endif
