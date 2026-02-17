/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:41:45 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 09:44:56 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/types.h>	// provides size_t, ssize_t
#include <stdbool.h>    // bool

int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
int		ft_atou(const char *nptr);
void	*ft_memset(void *address, int byte, size_t size);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_skip_spaces(const char *str);
bool	ft_streq(const char *s1, const char *s2);
ssize_t	ft_zimax(ssize_t a, ssize_t b);
int		ft_putchar(int c);
