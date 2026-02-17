/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:57:16 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/17 11:15:20 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffering.h"

int	ft_putchar(int c)
{
	return (append_to_buffer((unsigned char)c));
}
