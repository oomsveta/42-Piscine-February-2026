/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_words.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:27:00 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 21:44:05 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush_02.h"

char	*get_custom_entry(t_dict *dict, const char *nptr)
{
	t_list	*node;

	node = lst_find(dict->customs, (char *)nptr, custom_entry_cmp);
	if (!node)
	{
		return (NULL);
	}
	return (((t_custom_entry *)node->data)->word_form);
}

char	*get_magnitude(t_dict *dict, const char *nptr)
{
	size_t	magnitude_len;
	t_list	*node;

	magnitude_len = (ft_strlen(nptr) - 1) / 3 * 3 + 1;
	if (magnitude_len < 4)
	{
		return ("");
	}
	node = lst_find(dict->magnitudes, &magnitude_len, magnitude_cmp);
	if (!node)
	{
		return (NULL);
	}
	return (((t_magnitude *)node->data)->word_form);
}

char	*get_ones(t_dict *dict, unsigned int n)
{
	t_list	*node;

	node = lst_find(dict->customs, &n, custom_from_int_cmp);
	if (node)
	{
		return (((t_custom_entry *)node->data)->word_form);
	}
	return (dict->ones[n]);
}

char	*get_tens(t_dict *dict, unsigned int n)
{
	t_list	*node;

	node = lst_find(dict->customs, &n, custom_from_int_cmp);
	if (node)
	{
		return (((t_custom_entry *)node->data)->word_form);
	}
	return (dict->tens[n]);
}
