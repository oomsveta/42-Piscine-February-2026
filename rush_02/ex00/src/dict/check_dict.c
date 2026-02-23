/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:13:53 by ldeutsch          #+#    #+#             */
/*   Updated: 2026/02/22 21:39:21 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "dict.h"

static bool	validate_tens(t_dict *dict)
{
	size_t	i;

	i = 2;
	while (i < sizeof dict->tens / sizeof(*dict->tens))
	{
		if (dict->tens[i] == NULL)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	validate_ones(t_dict *dict)
{
	size_t	i;

	i = 0;
	while (i < sizeof dict->ones / sizeof(*dict->ones))
	{
		if (dict->ones[i] == NULL)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

/**
 * Checks that the dictionary has words for all magnitudes up to
 * 1000000000000000000000000000000000000 (37-character long).
 */
static bool	validate_magnitudes(t_dict *dict)
{
	size_t	magnitude;

	magnitude = 4;
	while (magnitude <= 37)
	{
		if (!lst_find(dict->magnitudes, &magnitude, magnitude_cmp))
		{
			return (false);
		}
		magnitude += 3;
	}
	return (true);
}

int	check_dict(t_dict *dict)
{
	return (
		validate_magnitudes(dict)
		&& validate_ones(dict)
		&& validate_tens(dict)
	);
}
