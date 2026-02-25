/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:50:19 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/25 18:47:32 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides size_t, STDERR_FILENO, write
#include <stdio.h>	// provides EOF
#include "ft.h"		// provides ft_strlen

int	ft_puterr(const char *error_msg)
{
	ssize_t	bytes_written;

	bytes_written = write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	if (bytes_written == -1)
	{
		return (EOF);
	}
	if (write(STDERR_FILENO, "\n", 1) == -1)
	{
		return (EOF);
	}
	return (bytes_written + 1);
}
