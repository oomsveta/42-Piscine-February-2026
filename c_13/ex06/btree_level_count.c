/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:34:47 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 16:37:10 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

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

#ifdef TEST

// clang btree_level_count.c -W{all,extra,error} && ./a.out
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
	assert(btree_level_count(&a) == 3);
	assert(btree_level_count(NULL) == 0);
	puts("✅ All tests passed");
}

#endif
