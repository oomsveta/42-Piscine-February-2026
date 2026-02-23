/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:45:19 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 21:06:54 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>		// provides open, O_RDONLY
#include <stdlib.h>		// provides EXIT_FAILURE, free
#include <unistd.h>		// provides close
#include "rush_02.h"

/**
 * Consumes lines until the entire file has been read.
 * Reading the file through the end allows the internal buffer of read_line to
 * release its resources, avoiding memory leaks.
 *
 * @param fd File descriptor of the file being read.
 */
static void	consume_lines(int fd)
{
	char	*line;

	line = read_line(fd);
	while (line != NULL)
	{
		free(line);
		line = read_line(fd);
	}
}

static void	free_resources(t_dict *dict)
{
	size_t	i;

	i = 0;
	while (i < (sizeof dict->ones / sizeof(*dict->ones)))
	{
		free(dict->ones[i]);
		i += 1;
	}
	i = 0;
	while (i < (sizeof dict->tens / sizeof(*dict->tens)))
	{
		free(dict->tens[i]);
		i += 1;
	}
	lst_free(&dict->magnitudes, free_magnitude);
	lst_free(&dict->customs, free_custom_entry);
	*dict = (t_dict){0};
}

static bool	load_dictionary(const char *filename, t_dict *dict)
{
	int		fd;
	char	*entry;

	*dict = (t_dict){0};
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (false);
	}
	entry = read_line(fd);
	while (entry != NULL)
	{
		if (parse_dict_entry(entry, dict) != SUCCESS)
		{
			free(entry);
			consume_lines(fd);
			return (false);
		}
		free(entry);
		entry = read_line(fd);
	}
	close(fd);
	return (check_dict(dict));
}

static bool	parse_args(int argc, char *argv[], const char **file, char **nbr)
{
	if (argc < 2)
	{
		puterr("Error: Not enough arguments");
		return (false);
	}
	if (argc > 3)
	{
		puterr("Error: Too many arguments");
		return (false);
	}
	if (argc == 2)
	{
		*file = DICT_FILENAME;
		*nbr = argv[1];
	}
	else
	{
		*file = argv[1];
		*nbr = argv[2];
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	t_dict		dict;
	const char	*dict_filename = DICT_FILENAME;
	char		*number_to_convert;

	if (!parse_args(argc, argv, &dict_filename, &number_to_convert))
	{
		return (EXIT_FAILURE);
	}
	if (!load_dictionary(dict_filename, &dict))
	{
		puterr("Dict Error");
		free_resources(&dict);
		return (EXIT_FAILURE);
	}
	if (ft_streq(number_to_convert, "-"))
	{
		repl(&dict);
	}
	else
	{
		number_to_words(&dict, number_to_convert);
	}
	free_resources(&dict);
}
