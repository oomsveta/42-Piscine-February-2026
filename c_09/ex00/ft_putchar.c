/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:20:28 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 16:40:47 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // provides STDOUT_FILENO, write

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, sizeof c);
}
