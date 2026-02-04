/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:19:40 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/04 11:45:02 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides size_t, STDOUT_FILENO, write

static int	ft_isprint(int c)
{
	return ((unsigned int)c - ' ' < 95u);
}

static void	ft_putchar(int c)
{
	write(STDOUT_FILENO, &c, 1);
}

static void	print_hex(int c)
{
	const char	*hex_digits = "0123456789abcdef";
	char		buffer[3];

	buffer[0] = '\\';
	buffer[1] = hex_digits[c >> 4];
	buffer[2] = hex_digits[c & 15];
	write(STDOUT_FILENO, buffer, sizeof buffer);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (ft_isprint(*str))
		{
			ft_putchar(*str);
		}
		else
		{
			print_hex(*str);
		}
		str += 1;
	}
}

// run with test main:
// clang ft_putstr_non_printable.c -W{all,extra,error} -DTEST && ./a.out
#ifdef TEST

int	main(void)
{
	ft_putstr_non_printable("Hello\nHow are you?");
}

#endif
