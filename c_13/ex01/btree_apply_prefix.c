/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:19:08 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/13 09:59:21 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <stddef.h>
# include <stdio.h>
#endif

#include "ft_btree.h"	// provides t_btree

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
	{
		return ;
	}
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}

#ifdef TEST

// run with test main:
// clang -W{all,extra} btree_apply_prefix.c -DTEST && ./a.out
int	main(void)
{
	t_btree	a;
	t_btree	b;
	t_btree	c;
	t_btree	d;
	t_btree	e;

	a = (t_btree){.left = &b, .right = &c, .item = "1"};
	b = (t_btree){.left = &d, .right = &e, .item = "2"};
	c = (t_btree){.left = NULL, .right = NULL, .item = "5"};
	d = (t_btree){.left = NULL, .right = NULL, .item = "3"};
	e = (t_btree){.left = NULL, .right = NULL, .item = "4"};
	btree_apply_prefix(&a, (void (*)(void *))puts);
}

#endif
