/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:59:33 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 21:43:37 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

char	*ft_strndup(const char *str, size_t n)
{
	char			*dup;
	size_t			i;
	const size_t	len = ft_strnlen(str, n);

	dup = malloc(len + 1);
	if (!dup)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i += 1;
	}
	dup[len] = '\0';
	return (dup);
}
