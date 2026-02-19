/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:48:27 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/19 10:46:18 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include "ft.h"
#include "ft_tail.h"
#include "buffering.h"

t_ring_buffer	init_ring_buffer(size_t size)
{
	t_ring_buffer	buffer;

	buffer = (t_ring_buffer){0};
	buffer.data = malloc(size);
	if (!buffer.data)
	{
		return (buffer);
	}
	buffer.capacity = size;
	return (buffer);
}

// TODO: Makefile should compile with NDEBUG
void	append_to_ring_buffer(t_ring_buffer *buffer, char c)
{
	assert(buffer->capacity > 0);
	buffer->data[buffer->total_written % buffer->capacity] = c;
	buffer->total_written += 1;
}

int	print_ring_buffer(t_ring_buffer *buffer)
{
	size_t	i;
	size_t	n;
	size_t	start_offset;
	char	to_print;

	assert(buffer->data && buffer->capacity > 0);
	if (buffer->total_written < buffer->capacity)
	{
		n = buffer->total_written;
		start_offset = 0;
	}
	else
	{
		n = buffer->capacity;
		start_offset = buffer->total_written % buffer->capacity;
	}
	i = 0;
	while (i < n)
	{
		to_print = buffer->data[(start_offset + i) % buffer->capacity];
		if (ft_putchar(to_print) == -1)
			return (-1);
		i += 1;
	}
	return (flush_buffer());
}

void	free_ring_buffer(t_ring_buffer *buffer)
{
	free(buffer->data);
	*buffer = (t_ring_buffer){0};
}
