/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:50:19 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/25 14:33:31 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides ssize_t, size_t, STDOUT_FILENO, write
#include <stdio.h>	// provides EOF
#include "libft.h"	// provides ft_strlen

int	ft_puts(const char *s)
{
	ssize_t	bytes_written;

	bytes_written = write(STDOUT_FILENO, s, ft_strlen(s));
	if (bytes_written == -1)
	{
		return (EOF);
	}
	if (write(STDOUT_FILENO, "\n", 1) == -1)
	{
		return (EOF);
	}
	return (bytes_written + 1);
}
