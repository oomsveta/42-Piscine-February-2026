/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:37:55 by tmattela          #+#    #+#             */
/*   Updated: 2026/02/22 23:13:04 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush_02.h"

void	append_word(char *str, bool *is_first)
{
	if (*str == '\0')
	{
		return ;
	}
	if (!*is_first)
	{
		write(STDOUT_FILENO, " ", 1);
	}
	ft_putstr(str);
	*is_first = false;
}

static void	print_triad(t_dict *dict, unsigned int n, bool *is_first)
{
	t_list	*node;

	node = lst_find(dict->customs, &n, custom_from_int_cmp);
	if (node)
	{
		append_word(((t_custom_entry *)node->data)->word_form, is_first);
		return ;
	}
	if (n >= 100)
	{
		append_word(get_ones(dict, n / 100), is_first);
		append_word(dict->tens[10], is_first);
		n %= 100;
	}
	if (n > 0)
	{
		print_sub_100(dict, n, is_first);
	}
}

static char	*handle_edge_cases(t_dict *dict, const char **nptr, bool *is_first)
{
	if (!validate_number(*nptr))
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	if (**nptr == '-')
	{
		append_word("minus", is_first);
		*nptr += 1;
	}
	else if (**nptr == '+')
	{
		*nptr += 1;
	}
	if (ft_streq(*nptr, "0"))
	{
		append_word(dict->ones[0], is_first);
		*nptr += 1;
	}
	return ((char *)*nptr);
}

static bool	print_custom_entry(t_dict *dict, const char *nptr)
{
	char	*custom;

	custom = get_custom_entry(dict, nptr);
	if (custom)
	{
		ft_putstr(custom);
		write(STDOUT_FILENO, "\n", 1);
		return (true);
	}
	return (false);
}

void	number_to_words(t_dict *dict, const char *nptr)
{
	unsigned int	triad;
	char			*magnitude;
	bool			is_first;

	is_first = true;
	if (!handle_edge_cases(dict, &nptr, &is_first)
		|| print_custom_entry(dict, nptr))
		return ;
	while (*nptr != '\0')
	{
		magnitude = get_magnitude(dict, nptr);
		triad = next_triad(&nptr);
		if (!magnitude)
		{
			ft_putstr("\33[2K\rDict Error\n");
			return ;
		}
		if (triad > 0)
		{
			print_triad(dict, triad, &is_first);
			if (*magnitude)
				append_word(magnitude, &is_first);
		}
	}
	write(STDOUT_FILENO, "\n", 1);
}
