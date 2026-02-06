/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:46:48 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/06 23:08:35 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

#include <stddef.h>		// provides NULL, size_t
#include <stdbool.h>	// provides true

static char	*ft_strchr(const char *str, int c)
{
	c = (unsigned char)c;
	while (true)
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

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
	{
		return (0);
	}
	while (*s1 == *s2 && *s1 != '\0' && --n != 0)
	{
		s1 += 1;
		s2 += 1;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*ft_strstr(char *str, char *to_find)
{
	size_t	len;
	char	*match_start;

	if (!*to_find)
	{
		return (str);
	}
	len = ft_strlen(to_find);
	while (*str)
	{
		match_start = ft_strchr(str, *to_find);
		if (!match_start)
		{
			break ;
		}
		if (ft_strncmp(match_start, to_find, len) == 0)
		{
			return ((char *)match_start);
		}
		str = (char *)match_start + 1;
	}
	return (NULL);
}

#ifdef TEST

// run with test main:
// clang ft_strstr.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char	buffer[64];

	memset(buffer, '\0', sizeof buffer);
	strcpy(buffer, "According to all known laws of the aviation,");
	assert(ft_strstr(buffer, "laws") == strstr(buffer, "laws"));
	memset(buffer, '\0', sizeof buffer);
	strcpy(buffer, "there is no way a bee should be able to fly.");
	assert(ft_strstr(buffer, "") == buffer);
	memset(buffer, '\0', sizeof buffer);
	strcpy(buffer, "Yellow, black. Yellow, black");
	assert(ft_strstr(buffer, "black") == strstr(buffer, "black"));
	memset(buffer, '\0', sizeof buffer);
	strcpy(buffer, "Ooming!");
	assert(ft_strstr(buffer, "Coming!") == NULL);
	memset(buffer, '\0', sizeof buffer);
	strcpy(buffer, "Hey, Barry.");
	assert(ft_strstr(buffer, "Barry?") == NULL);
	puts("✅ All tests passed");
}

#endif
