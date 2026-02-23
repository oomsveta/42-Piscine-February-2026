/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:17:30 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/21 14:58:13 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int chr)
{
	chr = (unsigned char)chr;
	while (1)
	{
		if ((unsigned char)*str == chr)
		{
			return ((char *)str);
		}
		if (*str == '\0')
		{
			return (NULL);
		}
		str += 1;
	}
}
