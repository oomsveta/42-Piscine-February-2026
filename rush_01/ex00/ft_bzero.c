/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:37:46 by mbuchet           #+#    #+#             */
/*   Updated: 2026/02/15 16:30:30 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*bytes;
	size_t			i;

	bytes = ptr;
	i = 0;
	while (i < n)
	{
		bytes[i] = '\0';
		i += 1;
	}
}
