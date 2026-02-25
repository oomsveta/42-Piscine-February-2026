/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:27:47 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/25 15:21:58 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>
#include <stdbool.h>

int				ft_isprint(int c);
int				ft_puts(const char *s);
size_t			ft_strlen(const char *str);
unsigned int	ft_umin(unsigned int a, unsigned int b);
void			*ft_malloc(void *dest, size_t n);
void			*ft_memchr(const void *buffer, int chr, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_realloc(void *buffer, size_t current_size, size_t new_size);
