/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:25:56 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 22:56:32 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <stdlib.h>

t_parsing_status	parse_ones(const char *entry, t_dict *dict, size_t nbr_len)
{
	size_t	idx;
	size_t	entry_len;

	if (!is_ones(entry, nbr_len))
		return (WRONG_NUMBER_TYPE);
	idx = substr_to_uint(entry, nbr_len);
	entry += nbr_len;
	entry += ft_strspn(entry, " ");
	if (*entry != ':')
		return (SYNTAX_ERROR);
	entry += 1;
	entry += ft_strspn(entry, " ");
	entry_len = ft_strcspn(entry, "\n");
	if (dict->ones[idx] != NULL)
		return (DUPLICATE_ERROR);
	dict->ones[idx] = ft_strndup(entry, entry_len);
	if (dict->ones[idx] == NULL)
		return (MALLOC_FAILURE);
	return (SUCCESS);
}

t_parsing_status	parse_tens(const char *entry, t_dict *dict, size_t nbr_len)
{
	size_t	idx;
	size_t	entry_len;

	if (!is_tens(entry, nbr_len))
		return (WRONG_NUMBER_TYPE);
	idx = substr_to_uint(entry, nbr_len) / 10;
	entry += nbr_len;
	entry += ft_strspn(entry, " ");
	if (*entry != ':')
		return (SYNTAX_ERROR);
	entry += 1;
	entry += ft_strspn(entry, " ");
	entry_len = ft_strcspn(entry, "\n");
	if (dict->tens[idx] != NULL)
		return (DUPLICATE_ERROR);
	dict->tens[idx] = ft_strndup(entry, entry_len);
	if (dict->tens[idx] == NULL)
		return (MALLOC_FAILURE);
	return (SUCCESS);
}

t_parsing_status	parse_mags(const char *entry, t_dict *dict, size_t nbr_len)
{
	size_t		entry_len;
	t_magnitude	*magnitude;

	if (!is_magnitudes(entry, nbr_len))
		return (WRONG_NUMBER_TYPE);
	entry += nbr_len;
	entry += ft_strspn(entry, " ");
	if (*entry++ != ':')
		return (SYNTAX_ERROR);
	entry += ft_strspn(entry, " ");
	entry_len = ft_strcspn(entry, "\n");
	if (entry[entry_len] != '\n')
		return (SYNTAX_ERROR);
	magnitude = malloc(sizeof(t_magnitude));
	if (magnitude == NULL)
		return (MALLOC_FAILURE);
	*magnitude = (t_magnitude){.length = nbr_len,
		.word_form = ft_strndup(entry, entry_len)};
	if (magnitude->word_form == NULL || magnitude == NULL)
		return (MALLOC_FAILURE);
	if (lst_find(dict->magnitudes, &nbr_len, magnitude_cmp))
		return (DUPLICATE_ERROR);
	if (!lst_prepend(&dict->magnitudes, magnitude))
		return (MALLOC_FAILURE);
	return (SUCCESS);
}

t_parsing_status	parse_c(const char *entry, t_dict *dict, size_t nbr_len)
{
	size_t			entry_len;
	t_custom_entry	*custom;

	custom = malloc(sizeof(t_custom_entry));
	if (custom == NULL)
		return (MALLOC_FAILURE);
	*custom = (t_custom_entry){.nbr = ft_strndup(entry, nbr_len)};
	entry += nbr_len;
	entry += ft_strspn(entry, " ");
	if (*entry++ != ':')
		return (SYNTAX_ERROR);
	entry += ft_strspn(entry, " ");
	entry_len = ft_strcspn(entry, "\n");
	if (entry[entry_len] != '\n')
		return (SYNTAX_ERROR);
	custom->word_form = ft_strndup(entry, entry_len);
	if (custom->word_form == NULL || custom->nbr == NULL)
		return (MALLOC_FAILURE);
	if (lst_find(dict->customs, custom->nbr, custom_entry_cmp))
		return (DUPLICATE_ERROR);
	if (!lst_prepend(&dict->customs, custom))
		return (MALLOC_FAILURE);
	return (SUCCESS);
}

t_parsing_status	parse_dict_entry(const char *entry, t_dict *dict)
{
	size_t				nbr_len;
	t_parsing_status	status;

	if (*entry == '\n')
		return (SUCCESS);
	if (!ft_isdigit(*entry))
		return (SYNTAX_ERROR);
	nbr_len = ft_strspn(entry, "0123456789");
	status = parse_ones(entry, dict, nbr_len);
	if (status <= 0)
	{
		return (status);
	}
	status = parse_tens(entry, dict, nbr_len);
	if (status <= 0)
	{
		return (status);
	}
	status = parse_mags(entry, dict, nbr_len);
	if (status <= 0)
	{
		return (status);
	}
	return (parse_c(entry, dict, nbr_len));
}
