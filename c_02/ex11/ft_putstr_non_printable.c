/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:19:40 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/06 11:53:20 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides size_t, STDOUT_FILENO, write

static int	ft_isprint(int c)
{
	return ((unsigned int)c - ' ' < 95u);
}

static void	ft_putchar(int c)
{
	const unsigned char	uc = (const unsigned char)c;

	write(STDOUT_FILENO, &uc, 1);
}

static void	print_byte(unsigned char byte)
{
	const char	*hex_digits = "0123456789abcdef";
	char		buffer[3];

	buffer[0] = '\\';
	buffer[1] = hex_digits[byte >> 4];
	buffer[2] = hex_digits[byte & 15];
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
			print_byte(*(unsigned char *)str);
		}
		str += 1;
	}
}

// run with test main:
// clang ft_putstr_non_printable.c -W{all,extra,error} -DTEST && ./a.out
#ifdef TEST

int	main(void)
{
	ft_putstr_non_printable("Hello\nHow are you?Test\x80");
}

#endif
