/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:07:00 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/04 00:14:42 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isalnum(int c)
{
	return (
		((unsigned int)c | 0x20) - 'a' < 26u ||
		(unsigned int)c - '0' < 10u
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
			*str = ft_toupper(*str);
		}
		else
		{
			*str = ft_tolower(*str);
		}
	}
	return ((char *)s0);
}
