/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:49:18 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/19 14:55:59 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>	// provides ssize_t

int				tail(const char *fname, ssize_t n, bool header);
void			print_errno(const char *filename);
void			print_error(const char *msg, const char *extra);

// =======
// Parsing
// =======

enum e_parsing_status
{
	NO_OPTIONS = -3,
	MISSING_ARG = -2,
	NOT_A_NUMBER = -1,
};

ssize_t			parse_byte_option(const char *args[]);
size_t			count_filenames(const char *args[]);

// ===============
// File Management
// ===============

typedef struct s_file
{
	const char	*name;
	int			fd;
}	t_file;

t_file			open_file(const char *filename);
int				close_file(t_file file);

// ===============
// Circular Buffer
// ===============

typedef struct s_ring_buffer
{
	char	*data;
	ssize_t	total_written;
	int		capacity;
}	t_ring_buffer;

t_ring_buffer	init_ring_buffer(size_t size);
void			append_to_ring_buffer(t_ring_buffer *buffer, char c);
int				print_ring_buffer(t_ring_buffer *buffer);
void			free_ring_buffer(t_ring_buffer *buffer);
