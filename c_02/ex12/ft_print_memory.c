/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:31:54 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/10 10:14:25 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>	// provides CHAR_BIT
#include <stdint.h>	// provides uintptr_t
#include <unistd.h>	// provides size_t, STDOUT_FILENO, write

#define LINE_WIDTH 16

static void	print_byte(unsigned char byte)
{
	const char	*hex_digits = "0123456789abcdef";
	const char	buffer[2] = {hex_digits[byte >> 4], hex_digits[byte & 15]};

	write(STDOUT_FILENO, buffer, sizeof buffer);
}

static void	print_address(const void *ptr)
{
	const uintptr_t	addr = (const uintptr_t)ptr;
	unsigned int	shift;
	unsigned char	byte;

	shift = sizeof(void *) * CHAR_BIT;
	while (shift != 0)
	{
		shift -= CHAR_BIT;
		byte = (unsigned char)(addr >> shift);
		print_byte(byte);
	}
}

static void	hexdump(const void *buffer, size_t size)
{
	const unsigned char	*bytes = (const unsigned char *)buffer;
	const size_t		padding_len = LINE_WIDTH * 5 / 2 - size * 5 / 2;
	size_t				i;

	i = 0;
	while (i < size)
	{
		print_byte(bytes[i]);
		if (i & 1)
		{
			write(STDOUT_FILENO, " ", 1);
		}
		i += 1;
	}
	i = 0;
	while (i < padding_len)
	{
		write(STDOUT_FILENO, " ", 1);
		i += 1;
	}
}

static void	print_as_text(const void *buffer, size_t size)
{
	const unsigned char	*bytes = (const unsigned char *)buffer;
	size_t				i;

	i = 0;
	while (i < size)
	{
		if (bytes[i] - ' ' < 95u)
		{
			write(STDOUT_FILENO, &bytes[i], 1);
		}
		else
		{
			write(STDOUT_FILENO, ".", 1);
		}
		i += 1;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	const unsigned char	*bytes = (const unsigned char *)addr;
	size_t				chunk_size;
	size_t				i;

	if (size == 0)
	{
		return (addr);
	}
	i = 0;
	while (i < size)
	{
		chunk_size = size - i;
		if (chunk_size > LINE_WIDTH)
		{
			chunk_size = LINE_WIDTH;
		}
		print_address(bytes + i);
		write(STDOUT_FILENO, ": ", 2);
		hexdump(bytes + i, chunk_size);
		print_as_text(bytes + i, chunk_size);
		write(STDOUT_FILENO, "\n", 1);
		i += LINE_WIDTH;
	}
	return (addr);
}

/* 
// clang ft_print_memory.c -W{all,extra,error} && ./a.out
int	main(void)
{
	const char	example[] = ""
		"Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on"
		" peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";

	ft_print_memory((void *)example, sizeof example);
} */
