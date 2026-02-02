/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:23:59 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/02 19:25:11 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides STDOUT_FILENO, write

void	ft_print_alphabet(void)
{
	write(STDOUT_FILENO, "abcdefghijklmnopqrstuvwxyz", 26);
}
