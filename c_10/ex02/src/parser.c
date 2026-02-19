/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:32:52 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/19 15:34:06 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_tail.h"
#include <sys/types.h>	// provides ssize_t
#include <stddef.h>		// provides NULL

static const char	*extract_byte_option(
	const char *current_arg, const char *next_arg
)
{
	if (current_arg[2] != '\0')
	{
		return (current_arg + 2);
	}
	return (next_arg);
}

static ssize_t	parse_value(const char *arg)
{
	size_t	value;

	if (!arg)
	{
		return (MISSING_ARG);
	}
	arg = ft_skip_spaces(arg);
	value = 0;
	while (ft_isdigit(*arg))
	{
		value = value * 10 + *arg++ - '0';
	}
	if (*arg != '\0')
	{
		return (NOT_A_NUMBER);
	}
	return (value);
}

/**
 * Counts how many strings are neither the -c option or its value.
 *
 * @param args Pointer to argv[1].
 *
 * @return The number of arguments that appear to be filenames.
 */
size_t	count_filenames(const char *args[])
{
	size_t	nbr_of_files;
	size_t	i;

	nbr_of_files = 0;
	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strncmp(args[i], "-c", 2) != 0)
		{
			nbr_of_files += 1;
			i += 1;
			continue ;
		}
		if (args[i][2] == '\0' && args[i + 1] != NULL)
		{
			i += 2;
		}
		else
		{
			i += 1;
		}
	}
	return (nbr_of_files);
}

ssize_t	parse_byte_option(const char *args[])
{
	size_t		i;
	ssize_t		val;
	const char	*str;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strncmp(args[i], "-c", 2) == 0)
		{
			str = extract_byte_option(args[i], args[i + 1]);
			val = parse_value(str);
			if (val == NOT_A_NUMBER)
			{
				print_error("invalid number of bytes: ", str);
			}
			else if (val == MISSING_ARG)
			{
				print_error("option requires an argument -- 'c'", NULL);
			}
			return (val);
		}
		i += 1;
	}
	return (NO_OPTIONS);
}
