/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:09:05 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 11:30:45 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides malloc, NULL, size_t

static size_t	ft_strspn(const char *str, const char *accept)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (str[len] != '\0')
	{
		i = 0;
		while (accept[i] != '\0' && accept[i] != str[len])
		{
			i += 1;
		}
		if (accept[i] == '\0')
		{
			break ;
		}
		len += 1;
	}
	return (len);
}

static size_t	ft_strcspn(const char *str, const char *reject)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		i = 0;
		while (reject[i] != '\0')
		{
			if (reject[i] == str[len])
			{
				return (len);
			}
			i += 1;
		}
		len += 1;
	}
	return (len);
}

static char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	size_t	len;
	char	*dup;

	len = 0;
	while (len < n && str[len] != '\0')
	{
		len += 1;
	}
	dup = malloc(len + 1);
	dup[len] = '\0';
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
	return (dup);
}

static size_t	count_words(const char *str, const char *separators)
{
	size_t	nbr_of_words;

	str += ft_strspn(str, separators);
	nbr_of_words = 0;
	while (*str != '\0')
	{
		nbr_of_words += 1;
		str += ft_strcspn(str, separators);
		str += ft_strspn(str, separators);
	}
	return (nbr_of_words);
}

char	**ft_split(char *str, char *charset)
{
	const size_t	nbr_of_words = count_words(str, charset);
	char			**words;
	size_t			i;
	size_t			substr_len;

	words = malloc(sizeof(char *) * (nbr_of_words + 1));
	if (!words)
	{
		return (NULL);
	}
	words[nbr_of_words] = NULL;
	str += ft_strspn(str, charset);
	i = 0;
	while (i < nbr_of_words)
	{
		substr_len = ft_strcspn(str, charset);
		words[i] = ft_strndup(str, substr_len);
		str += substr_len;
		str += ft_strspn(str, charset);
		i += 1;
	}
	return (words);
}

/* 
#include <assert.h>
#include <stdio.h>
#include <string.h>

// clang ft_split.c -W{all,extra} -fsanitize=address && ./a.out
int	main(void)
{
	const char	test[] = "  yo, la  team";
	char		**res;

	res = ft_split((char *)test, " ,");
	assert(strcmp(res[0], "yo") == 0);
	assert(strcmp(res[1], "la") == 0);
	assert(strcmp(res[2], "team") == 0);
	assert(res[3] == NULL);
	free(res[0]);
	free(res[1]);
	free(res[2]);
	free(res);
	puts("✅ All tests passed");
}
*/
