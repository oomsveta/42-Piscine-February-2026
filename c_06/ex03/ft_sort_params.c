/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 08:59:57 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/06 09:10:36 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides EXIT_SUCCESS

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1 += 1;
		s2 += 1;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		return (EXIT_SUCCESS);
	}
}
