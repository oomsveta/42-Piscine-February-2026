/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:20:28 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/08 12:49:33 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // provides STDOUT_FILENO, write

void	ft_putchar(int c)
{
	const unsigned char	byte = (const unsigned char)c;

	write(STDOUT_FILENO, &byte, sizeof byte);
}
