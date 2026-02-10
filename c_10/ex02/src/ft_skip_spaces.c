/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:21:36 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/10 13:21:40 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(int c)
{
	return (c == ' ' || (unsigned int)c - '\t' < 5u);
}

char	*ft_skip_spaces(const char *str)
{
	while (ft_isspace(*str))
	{
		str += 1;
	}
	return ((char *)str);
}
