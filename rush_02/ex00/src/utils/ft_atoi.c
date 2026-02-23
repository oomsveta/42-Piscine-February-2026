/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:56:30 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 16:57:31 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	acc;

	acc = 0;
	while (ft_isdigit(*nptr))
	{
		acc = acc * 10 + *nptr++ - '0';
	}
	return (acc);
}
