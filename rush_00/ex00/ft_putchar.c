/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:51:41 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/07 21:21:21 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides STDOUT_FILENO, write

void	ft_putchar(int c)
{
	const unsigned char	byte = (const unsigned char)c;

	write(STDOUT_FILENO, &byte, 1);
}
