/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:41:04 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/25 11:30:33 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>		// provides size_t
#include <stdint.h>		// provides uint8_t, uint64_t, uintptr_t
#include <stdbool.h>	// provides bool

static inline bool	same_alignment_8(const void *ptr1, const void *ptr2)
{
	return ((((uintptr_t)ptr1 ^ (uintptr_t)ptr2) & 7) == 0);
}

static void	byte_by_byte_copy(
	unsigned char *dest, const unsigned char *src, size_t n
)
{
	while (n != 0)
	{
		*dest++ = *src++;
		n -= 1;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	uint8_t			*dest8;
	const uint8_t	*src8 = src;
	uint64_t		*dest64;
	const uint64_t	*src64;

	if (!same_alignment_8(dest, src))
	{
		byte_by_byte_copy((unsigned char *)dest, (const unsigned char *)src, n);
		return (dest);
	}
	dest8 = dest;
	while (n != 0 && ((uintptr_t)dest8 & 7))
	{
		*dest8++ = *src8++;
		n -= 1;
	}
	dest64 = (uint64_t *)dest8;
	src64 = (const uint64_t *)src8;
	while (n >= 8)
	{
		*dest64++ = *src64++;
		n -= 8;
	}
	byte_by_byte_copy((unsigned char *)dest64, (const unsigned char *)src64, n);
	return (dest);
}
