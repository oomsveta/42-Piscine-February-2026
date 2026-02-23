/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:03:15 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 18:03:15 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

#define READ_SIZE 1024

static	char	*resize_buffer(t_buffer *buffer)
{
	char	*new_buffer;
	size_t	new_capacity;

	new_capacity = ft_zmax(
			buffer->capacity + buffer->capacity / 2,
			buffer->length + READ_SIZE);
	if (buffer->capacity >= new_capacity)
	{
		return (NULL);
	}
	new_buffer = malloc(new_capacity);
	if (!new_buffer)
	{
		return (NULL);
	}
	ft_memcpy(new_buffer, buffer->content, buffer->length);
	free(buffer->content);
	buffer->content = new_buffer;
	buffer->capacity = new_capacity;
	return (new_buffer);
}

static ssize_t	read_more(int fd, t_buffer *buffer)
{
	ssize_t	bytes_read;

	if (buffer->capacity - buffer->length < READ_SIZE)
	{
		if (!resize_buffer(buffer))
		{
			return (-1);
		}
	}
	bytes_read = read(fd, buffer->content + buffer->length, READ_SIZE);
	if (bytes_read == -1)
	{
		return (-1);
	}
	buffer->length += bytes_read;
	return (bytes_read);
}

static char	*fetch_eol(int fd, t_buffer *buffer)
{
	char	*eol_ptr;
	ssize_t	bytes_read;
	size_t	offset;

	eol_ptr = ft_memchr(buffer->content, '\n', buffer->length);
	while (!eol_ptr)
	{
		offset = buffer->length;
		bytes_read = read_more(fd, buffer);
		if (bytes_read > 0)
		{
			eol_ptr = ft_memchr(buffer->content + offset, '\n', bytes_read);
			continue ;
		}
		if (buffer->length == 0)
		{
			return (NULL);
		}
		eol_ptr = buffer->content + buffer->length - 1;
	}
	return (eol_ptr);
}

static char	*extract_line(t_buffer *buffer, char *eol_ptr)
{
	char	*line;
	size_t	line_length;

	line_length = eol_ptr - buffer->content + 1;
	line = malloc(line_length + 1);
	if (!line)
	{
		free(buffer->content);
		*buffer = (t_buffer){NULL, 0, READ_SIZE};
		return (NULL);
	}
	line[line_length] = '\0';
	ft_memcpy(line, buffer->content, line_length);
	buffer->length -= line_length;
	ft_memmove(buffer->content, buffer->content + line_length, buffer->length);
	return (line);
}

char	*read_line(int fd)
{
	static t_buffer	buffer = {NULL, 0, READ_SIZE};
	char			*eol_ptr;

	if (!buffer.content)
	{
		buffer.content = malloc(buffer.capacity);
		if (!buffer.content)
		{
			return (NULL);
		}
	}
	eol_ptr = fetch_eol(fd, &buffer);
	if (!eol_ptr)
	{
		free(buffer.content);
		buffer = (t_buffer){NULL, 0, READ_SIZE};
		return (NULL);
	}
	return (extract_line(&buffer, eol_ptr));
}
