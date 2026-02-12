/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:38:40 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 18:44:44 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <stdio.h>
#endif

#include "ft_btree.h"	// provides t_btree

void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
	{
		return ;
	}
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}

#ifdef TEST

int	main(void)
{
	t_btree	a;
	t_btree	b;
	t_btree	c;
	t_btree	d;
	t_btree	e;

	a = (t_btree){.left = &b, .right = &c, .item = "5"};
	b = (t_btree){.left = &d, .right = &e, .item = "3"};
	c = (t_btree){.left = NULL, .right = NULL, .item = "4"};
	d = (t_btree){.left = NULL, .right = NULL, .item = "1"};
	e = (t_btree){.left = NULL, .right = NULL, .item = "2"};
	btree_apply_suffix(&a, (void (*)(void *))puts);
}

#endif
