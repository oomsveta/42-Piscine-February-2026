/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:41:45 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/10 13:21:49 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>	// provides size_t

int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
int     ft_atou(const char *nptr);
void	*ft_memset(void *address, int byte, size_t size);
int     ft_isdigit(int c);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_skip_spaces(const char *str);
