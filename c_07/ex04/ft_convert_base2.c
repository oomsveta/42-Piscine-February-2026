/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:29:14 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/07 18:46:44 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// malloc, NULL, size_t

char	*ft_strchr(const char *str, int c)
{
	c = (unsigned char)c;
	while (1)
	{
		if ((unsigned char)*str == c)
		{
			return ((char *)str);
		}
		if (*str == '\0')
		{
			return (NULL);
		}
		str += 1;
	}
}

char	*ft_skip_spaces(const char *str)
{
	while (*str == ' ' || (unsigned int)*str - '\t' < 5u)
	{
		str += 1;
	}
	return ((char *)str);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len += 1;
	}
	return (len);
}

char	*ft_strcpy(char *restrict dest, const char *restrict src)
{
	const char	*d0 = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return ((char *)d0);
}

char	*ft_strdup(const char *src)
{
	char	*dup;

	dup = malloc(ft_strlen(src) + 1);
	if (!dup)
	{
		return (NULL);
	}
	return (ft_strcpy(dup, src));
}
