/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwatelle <nwatelle@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:20:25 by mbuchet           #+#    #+#             */
/*   Updated: 2026/02/15 16:31:47 by nwatelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *str);

void	ft_putun(unsigned int n)
{
	char	buffer[64];
	char	*ptr;

	ptr = buffer + sizeof buffer;
	*--ptr = '\0';
	while (n >= 10)
	{
		*--ptr = n % 10 + '0';
		n /= 10;
	}
	*--ptr = n % 10 + '0';
	write(STDOUT_FILENO, ptr, ft_strlen(ptr));
}
