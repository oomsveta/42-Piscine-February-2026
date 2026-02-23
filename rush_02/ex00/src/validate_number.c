/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 11:17:29 by ldeutsch          #+#    #+#             */
/*   Updated: 2026/02/22 22:46:14 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	validate_number(const char *str)
{
	if (ft_streq(str, "-0"))
	{
		return (false);
	}
	if (*str == '-' || *str == '+')
	{
		str += 1;
	}
	if (!ft_isdigit(*str))
	{
		return (false);
	}
	if (str[0] == '0' && str[1] != '\0')
	{
		return (false);
	}
	str += 1;
	while (ft_isdigit(*str))
	{
		str += 1;
	}
	return (*str == '\0');
}
