/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 23:16:53 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 21:44:18 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush_02.h"

#define BUFFER_SIZE 128

void	process_line(t_dict *dict, char *buffer, size_t *length)
{
	buffer[*length] = '\0';
	number_to_words(dict, buffer);
	*length = 0;
}

bool	handle_overflow(t_dict *dict, char *buffer, size_t *length)
{
	if (*length == BUFFER_SIZE - 1)
	{
		ft_putstr("Line too long, input flushed automatically.\n");
		process_line(dict, buffer, length);
		return (true);
	}
	return (false);
}

void	repl(t_dict *dict)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	size_t	length;

	length = 0;
	while (true)
	{
		if (handle_overflow(dict, buffer, &length))
			continue ;
		bytes_read = read(STDIN_FILENO, buffer + length, 1);
		if (bytes_read < 0)
		{
			puterr("Error reading the file.");
			return ;
		}
		if (bytes_read == 0)
			break ;
		if (buffer[length] == '\n')
			process_line(dict, buffer, &length);
		else
			length += bytes_read;
	}
}
