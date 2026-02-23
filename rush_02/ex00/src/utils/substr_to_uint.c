/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_to_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:23:37 by ldeutsch          #+#    #+#             */
/*   Updated: 2026/02/22 18:04:09 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * Like atoi, but bound to a given length.
 */
unsigned int	substr_to_uint(const char *nptr, size_t len)
{
	unsigned int	acc;
	size_t			i;

	acc = 0;
	i = 0;
	while (i < len && ft_isdigit(nptr[i]))
	{
		acc = acc * 10 + nptr[i] - '0';
		i += 1;
	}
	return (acc);
}
