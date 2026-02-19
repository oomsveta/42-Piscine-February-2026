/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:08:52 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/19 10:46:49 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "buffering.h"

static t_buffer	g_buffer = {0};

int	flush_buffer(void)
{
	ssize_t	bytes_written;

	bytes_written = write(STDOUT_FILENO, g_buffer.data, g_buffer.length);
	g_buffer.length = 0;
	return (bytes_written);
}

int	append_to_buffer(unsigned char c)
{
	if (g_buffer.length == sizeof g_buffer.data)
	{
		return (flush_buffer());
	}
	g_buffer.data[g_buffer.length] = c;
	g_buffer.length += 1;
	return (1);
}
