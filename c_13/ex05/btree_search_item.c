/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:58:08 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/16 21:32:26 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>		// provides NULL
#include "ft_btree.h"	// provides t_btree

void	*btree_search_item(
	t_btree *root, void *data_ref, int (*cmpf)(void *, void *)
)
{
	void	*match;

	if (!root)
	{
		return (NULL);
	}
	match = btree_search_item(root->left, data_ref, cmpf);
	if (match)
	{
		return (match);
	}
	if (cmpf(root->item, data_ref) == 0)
	{
		return (root->item);
	}
	return (btree_search_item(root->right, data_ref, cmpf));
}
