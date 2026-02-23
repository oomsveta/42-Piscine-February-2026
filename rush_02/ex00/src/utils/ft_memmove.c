/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:34:25 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/21 21:09:30 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "utils.h"

/*
 * When dest > src, the beginning of the destination buffer overlaps with the
 * end of the source buffer.
 *
 * If we copy forward (0 -> n), we write new data into 'src' before we have a
 * chance to read the old data, effectively corrupting the source.
 *
 * SCENARIO: Moving [1, 2, 3] two steps to the right.
 *
 * Memory: [ 1 | 2 | 3 | . | . ]
 * Src:      ^_______^
 * Dest:             ^_______^
 *
 * 1. Forward Copy (BAD):
 *    Writes '1' to Dest[0]. But Dest[0] IS Src[2]
 *    Result: [ 1 | 2 | 1 | . | . ] -> We lost '3' forever.
 *
 * 2. Backward Copy (GOOD):
 *    Start from the end. Move '3' to the far right first.
 *    Result: [ 1 | 2 | 3 | . | 3 ] -> Data is safe.
 */
static void	*copy_descending(
	unsigned char *dest, const unsigned char *src, size_t n
)
{
	while (n != 0)
	{
		dest[n - 1] = src[n - 1];
		n -= 1;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
	{
		return (dest);
	}
	if ((uintptr_t)dest - (uintptr_t)src < n)
	{
		return (copy_descending(dest, src, n));
	}
	return (ft_memcpy(dest, src, n));
}
