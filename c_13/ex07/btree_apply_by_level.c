/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:32:38 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/15 11:49:28 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"	// provides t_btree

static int	ft_max(int a, int b)
{
	if (a >= b)
	{
		return (a);
	}
	return (b);
}

static int btree_level_count(t_btree *root)
{
	int	left_count;
	int	right_count;

	if (!root)
	{
		return (0);
	}
	left_count = btree_level_count(root->left);
	right_count = btree_level_count(root->right);
	return (1 + ft_max(left_count, right_count));
}


void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	
}
