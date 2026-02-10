/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:32:52 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/10 20:51:14 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum e_parsing_status
{
	NO_OPTIONS,
	MISSING_ARG,
	NOT_A_NUMBER,
};

#include "ft.h"
#include <stddef.h>
#include <sys/types.h>

ssize_t	parse_byte_option(const char *args[])
{
	const char	*nptr = NULL;

	while (*args)
	{
		if (ft_strncmp(*args, "-c", 2) != 0)
		{
			args += 1;
			continue ;
		}
		*args += 2;
		if (**args == '\0' && *++args == NULL)
		{
			return (MISSING_ARG);
		}
		nptr = ft_skip_spaces(*args);
		if (!ft_isdigit(*nptr))
		{
			return (NOT_A_NUMBER);
		}
		return (ft_atou(*args));
	}
	return (NO_OPTIONS);
}

int main(int argc, char *argv[])
{
	
}
