/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:20:06 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/02 22:28:46 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides STDOUT_FILENO, write

void	ft_is_negative(int n)
{
	write(STDOUT_FILENO, &"PN"[n < 0], 1);
}
