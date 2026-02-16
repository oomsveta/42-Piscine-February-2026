/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:03:55 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/16 21:34:24 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>	// provides bool

int	ft_count_if(char *tab[], int length, int (*f)(char *))
{
	int	i;
	int	acc;

	i = 0;
	acc = 0;
	while (i < length)
	{
		acc += (bool)f(tab[i]);
		i += 1;
	}
	return (acc);
}
