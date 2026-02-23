/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sub_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:06:14 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 23:08:32 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	print_sub_100(t_dict *dict, unsigned int n, bool *is_first)
{
	const t_list	*node;

	node = lst_find(dict->customs, &n, custom_from_int_cmp);
	if (node)
	{
		append_word(((t_custom_entry *)node->data)->word_form, is_first);
		return ;
	}
	if (n >= 20)
	{
		append_word(get_tens(dict, n / 10), is_first);
		n %= 10;
	}
	if (n > 0)
	{
		append_word(get_ones(dict, n), is_first);
	}
}
