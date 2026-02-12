/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:19:08 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 15:30:41 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"	// provides t_btree

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
	{
		return ;
	}
	if (root->left)
	{
		applyf(root->left);
	}
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}
