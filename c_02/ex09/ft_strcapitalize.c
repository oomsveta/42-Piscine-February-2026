/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:07:00 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/04 09:48:50 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

static int	ft_isalnum(int c)
{
	return (
		((unsigned int)c | 0x20) - 'a' < 26u
		|| (unsigned int)c - '0' < 10u
	);
}

static int	ft_tolower(int c)
{
	if ((unsigned int)c - 'A' < 26u)
	{
		return (c | 0x20);
	}
	return (c);
}

static int	ft_toupper(int c)
{
	if ((unsigned int)c - 'a' < 26u)
	{
		return (c ^ 0x20);
	}
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	const char	*s0 = str;

	if (*str == '\0')
	{
		return (str);
	}
	*str = ft_toupper(*str);
	while (*str++ != '\0')
	{
		if (ft_isalnum(str[-1]))
		{
			*str = ft_tolower(*str);
		}
		else
		{
			*str = ft_toupper(*str);
		}
	}
	return ((char *)s0);
}

#ifdef TEST

// run with test main:
// clang ft_strcapitalize.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	char	test_case[64];

	strcpy(
		test_case,
		"salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un");
	assert(
		strcmp(
			ft_strcapitalize(test_case),
			"Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un"
			) == 0
		);
	strcpy(test_case, "HELLO GUYS");
	assert(strcmp(ft_strcapitalize(test_case), "Hello Guys") == 0);
	strcpy(test_case, "");
	assert(strcmp(ft_strcapitalize(test_case), "") == 0);
	strcpy(test_case, "42@belgium");
	assert(strcmp(ft_strcapitalize(test_case), "42@Belgium") == 0);
	puts("✅ All tests passed");
}

#endif
