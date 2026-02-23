/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:20:04 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/21 20:31:11 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strspn(const char *str, const char *spn)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (!ft_strchr(spn, str[len]))
		{
			return (len);
		}
		len += 1;
	}
	return (len);
}
