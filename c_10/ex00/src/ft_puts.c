/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:50:19 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/08 16:05:20 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides size_t, STDOUT_FILENO, write
#include <stdio.h>	// provides EOF
#include "ft.h"		// provides ft_strlen

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
