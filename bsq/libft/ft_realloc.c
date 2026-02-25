/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:37:33 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/25 14:35:28 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides free, malloc, NULL, size_t
#include "libft.h"	// provides ft_memcpy

void	*ft_realloc(void *buffer, size_t current_size, size_t new_size)
{
	void	*new_buffer;

	if (new_size <= current_size)
	{
		return (buffer);
	}
	new_buffer = malloc(new_size);
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	ft_memcpy(new_buffer, buffer, current_size);
	free(buffer);
	return (new_buffer);
}
