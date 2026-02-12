/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:47:44 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/06 22:21:53 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides malloc, NULL, size_t

static char	*ft_stpcpy(char *restrict dest, const char *restrict src)
{
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest);
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

static char	*ft_strdup(char *src)
{
	char	*dup;

	dup = malloc(ft_strlen(src) + 1);
	if (!dup)
	{
		return (NULL);
	}
	ft_stpcpy(dup, src);
	return (dup);
}

static size_t	get_joined_len(size_t size, char *strs[], char *sep)
{
	size_t	len;
	size_t	i;

	len = (size - 1) * ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i += 1;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	char	*end_ptr;
	int		i;

	if (size == 0)
	{
		return (ft_strdup(""));
	}
	joined = malloc(get_joined_len(size, strs, sep) + 1);
	if (!joined)
	{
		return (NULL);
	}
	end_ptr = joined;
	i = 0;
	while (i < size)
	{
		end_ptr = ft_stpcpy(end_ptr, strs[i]);
		i += 1;
		if (i < size)
		{
			end_ptr = ft_stpcpy(end_ptr, sep);
		}
	}
	return (joined);
}

/*
#include <stdio.h>

// clang ft_strjoin.c -W{all,extra,error} -fsanitize=address && ./a.out
int	main(int argc, char *argv[])
{
	char	*joined;

	if (argc < 1)
	{
		return (EXIT_SUCCESS);
	}
	joined = ft_strjoin(argc - 1, argv + 1, ", ");
	puts(joined);
	free(joined);
}
*/
