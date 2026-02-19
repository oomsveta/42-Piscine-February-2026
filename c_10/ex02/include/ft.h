/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:41:45 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/19 13:05:05 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/types.h>	// provides size_t, ssize_t
#include <stdbool.h>    // bool

size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_skip_spaces(const char *str);
bool	ft_streq(const char *s1, const char *s2);
int		ft_putchar(int c);
