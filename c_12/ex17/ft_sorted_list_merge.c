/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:40:37 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 10:06:09 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>		// provides NULL
#include "ft_list.h"	// provides t_list

void	ft_sorted_list_merge(
	t_list **begin_list1, t_list *begin_list2, int (*cmp)()
)
{
	t_list	**current;
	t_list	*node_to_insert;

	current = begin_list1;
	while (*current != NULL && begin_list2 != NULL)
	{
		if (cmp((*current)->data, begin_list2->data) > 0)
		{
			node_to_insert = begin_list2;
			begin_list2 = begin_list2->next;
			node_to_insert->next = *current;
			*current = node_to_insert;
		}
		else
		{
			current = &(*current)->next;
		}
	}
	if (begin_list2 != NULL)
	{
		*current = begin_list2;
	}
}
