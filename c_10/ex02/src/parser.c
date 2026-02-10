/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:32:52 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/10 13:37:02 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum e_parsing_status
{
	NO_OPTIONS,
	MISSING_ARG,
	NOT_A_NUMBER,
};

#include <stddef.h>
#include <sys/types.h>

#define NO_OPTION -1
#define NAN_OPTION -2
#define MISSING_OPTION -3

ssize_t	parse_arg(const char *arg)
{
	if (!arg)
	{
		
	}
}

ssize_t	parse_byte_option(const char *args[])
{
	while (*args)
	{
		if (ft_strncmp(*args, "-c", 2) != 0)
		{
			continue ;
		}
		*args += 2;
		if (**args == '\0')
		{
			if (args[1] == )	
		}
		if (ft_isdigit(ft_skip_spaces(*args + 2)))
		{
			return (ft_atou(*args + 2));
		}
		if ()
		args += 1;
	}
}
