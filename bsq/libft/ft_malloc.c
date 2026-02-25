/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:39:52 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/25 14:30:02 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides malloc, size_t

void	*ft_malloc(void *dest, size_t n)
{
	*(void **)dest = malloc(n);
	return (*(void **)dest);
}
