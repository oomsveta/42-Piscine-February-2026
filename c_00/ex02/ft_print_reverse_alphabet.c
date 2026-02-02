/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:25:35 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/02 22:33:37 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides STDOUT_FILENO, write

// Generate alphabet backwards: echo {z..a} | tr -d ' '

void	ft_print_reverse_alphabet(void)
{
	write(STDOUT_FILENO, "zyxwvutsrqponmlkjihgfedcba", 26);
}
