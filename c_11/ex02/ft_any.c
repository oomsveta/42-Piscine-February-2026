/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:01:47 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/10 19:03:21 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// provides NULL

int	ft_any(char *tab[], int (*f)(char*))
{
	while (*tab != NULL)
	{
		if (f(*tab))
		{
			return (1);
		}
	}
	return (0);
}
