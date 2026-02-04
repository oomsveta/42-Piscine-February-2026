/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:55:44 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/04 17:02:07 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// provides size_t

static char	*ft_strcpy(char *dest, const char *src)
{
	const char	*d0 = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return ((char *)d0);
}


static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len += 1;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	const char	*d0 = dest;

	dest += ft_strlen(dest);
	ft_strcpy(dest, src);
	return ((char *)d0);
}
