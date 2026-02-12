/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:40:41 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 10:08:39 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"	// provides ft_create_elem, t_list
#include <stddef.h>		// provides NULL

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new_node;
	t_list	**current;

	new_node = ft_create_elem(data);
	if (!new_node)
	{
		return ;
	}
	current = begin_list;
	while (*current != NULL && cmp((*current)->data, data) < 0)
	{
		current = &(*current)->next;
	}
	new_node->next = *current;
	*current = new_node;
}
