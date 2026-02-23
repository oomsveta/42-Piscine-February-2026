/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:38:59 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/21 20:31:11 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memchr(const void *buffer, int chr, size_t n)
{
	const unsigned char	*bytes = buffer;

	chr = (unsigned char)chr;
	while (n != 0)
	{
		if (*bytes == chr)
		{
			return ((void *)bytes);
		}
		bytes += 1;
		n -= 1;
	}
	return (NULL);
}
