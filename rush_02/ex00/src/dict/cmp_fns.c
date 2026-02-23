/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_fns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 11:47:39 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 21:12:05 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "utils.h"

/**
 * Example usage:
 *  node = lst_find(dict->customs, "1337", custom_entry_cmp);
 *  puts(node->data->word_form); // Expected output: "leet"
 */
int	custom_entry_cmp(void *custom_entry, void *str)
{
	return (ft_strcmp((char *)str, ((t_custom_entry *)custom_entry)->nbr));
}

int	custom_from_int_cmp(void *custom_entry, void *val)
{
	return (ft_atoi(((t_custom_entry *)custom_entry)->nbr) - *(int *)val);
}

/**
 * Example usage:
 *	size_t len = 4
 *  node = lst_find(dict->magnitudes, &len, magnitude_cmp);
 *  puts(node->data->word_form); // Expected output: "thousand"
 */
int	magnitude_cmp(void *magnitude, void *len)
{
	return (*(int *)len - ((t_magnitude *)magnitude)->length);
}
