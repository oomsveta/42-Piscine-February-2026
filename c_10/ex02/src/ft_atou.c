/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:07:39 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/10 13:21:25 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atou(const char *nptr)
{
	unsigned int	acc;

	nptr = ft_skip_spaces(nptr);
	acc = 0;
	while (ft_isdigit(*nptr))
	{
		acc = acc * 10 + *nptr++ | '0';
	}
	return (acc);
}
