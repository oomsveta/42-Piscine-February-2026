/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:03:43 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/17 10:04:49 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft.h"

bool	ft_streq(const char *s1, const char *s2)
{
	return (ft_strcmp(s1, s2) == 0);
}
