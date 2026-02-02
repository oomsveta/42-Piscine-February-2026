/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:18:55 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/02 22:19:39 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides STDOUT_FILENO, write

void	ft_print_numbers(void)
{
	write(STDOUT_FILENO, "0123456789", 10);
}
