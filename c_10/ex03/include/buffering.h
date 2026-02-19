/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:12:02 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/19 17:23:12 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>	// provides size_t

typedef struct s_buffer
{
	unsigned char	data[1024];
	size_t			length;
}	t_buffer;

int	flush_buffer(void);
int	append_to_buffer(unsigned char c);
