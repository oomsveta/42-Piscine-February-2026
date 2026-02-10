/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:59:59 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/10 13:10:44 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// provides size_t
#include <stdint.h>	// provides uint8_t, uint64_t, uintptr_t

void	*ft_memset(void *address, int byte, size_t size)
{
	uint64_t	filler64;
	uint8_t		*ptr8;
	uint64_t	*ptr64;

	ptr8 = address;
	while (size != 0 && (uintptr_t)ptr8 & 7)
	{
		*ptr8++ = (uint8_t)byte;
		size -= 1;
	}
	filler64 = 0x0101010101010101ULL * (uint8_t)byte;
	ptr64 = (uint64_t *)ptr8;
	while (size >= 8)
	{
		*ptr64++ = filler64;
		size -= 8;
	}
	ptr8 = (uint8_t *)ptr64;
	while (size != 0)
	{
		*ptr8++ = (uint8_t)byte;
		size -= 1;
	}
	return (address);
}
