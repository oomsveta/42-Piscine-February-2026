/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_triad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 11:38:17 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 15:01:08 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

unsigned int	next_triad(const char **nptr)
{
	const size_t	len = ft_strlen(*nptr);
	size_t			substr_len;
	unsigned int	ret;

	if (len % 3 != 0)
	{
		substr_len = len % 3;
	}
	else
	{
		substr_len = 3;
	}
	ret = substr_to_uint(*nptr, substr_len);
	*nptr += substr_len;
	return (ret);
}
