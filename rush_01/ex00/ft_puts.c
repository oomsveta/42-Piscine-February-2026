/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:34:00 by nwatelle          #+#    #+#             */
/*   Updated: 2026/02/15 16:31:40 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *str);
void	ft_putchar(char c);

void	ft_puts(const char *str)
{
	write(1, str, ft_strlen(str));
	ft_putchar('\n');
}
