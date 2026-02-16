/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:34:47 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/16 21:32:51 by lwicket          ###   ########.fr       */
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

int	btree_level_count(t_btree *root)
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
