/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:12:35 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 13:16:12 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// provides malloc, NULL
#include "ft_btree.h"	// provides t_btree

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = malloc(sizeof(t_btree));
	if (!node)
	{
		return (NULL);
	}
	*node = (t_btree){.item = item, .left = NULL, .right = NULL};
	return (node);
}
