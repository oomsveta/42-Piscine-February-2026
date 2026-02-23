/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:09:35 by ldeutsch          #+#    #+#             */
/*   Updated: 2026/02/22 21:41:40 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>	// provides bool, false, true
#include <stddef.h>		// provides size_t

bool	is_ones(const char *entry, size_t nbr_len)
{
	if (!(nbr_len == 1 || (nbr_len == 2 && entry[0] == '1')))
	{
		return (false);
	}
	return (true);
}

bool	is_tens(const char *entry, size_t nbr_len)
{
	if (nbr_len == 3 && entry[0] == '1' && entry[1] == '0' && entry[2] >= '0')
	{
		return (true);
	}
	if (!(nbr_len == 2 && entry[0] >= '2' && entry[1] == '0'))
	{
		return (false);
	}
	return (true);
}

bool	is_magnitudes(const char *entry, size_t nbr_len)
{
	size_t	i;

	if (*entry != '1')
	{
		return (false);
	}
	if (nbr_len % 3 != 1)
	{
		return (false);
	}
	i = 1;
	while (i < nbr_len)
	{
		if (entry[i] != '0')
		{
			return (false);
		}
		i++;
	}
	return (true);
}
