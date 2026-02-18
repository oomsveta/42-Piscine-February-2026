/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:58:08 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 16:57:52 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

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

#ifdef TEST

int	cmp(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

// clang btree_search_item.c -W{all,extra,error} && ./a.out
// (doesn't test in-order traversal)
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
	assert(strcmp(btree_search_item(&a, "1", cmp), "1") == 0);
	assert(strcmp(btree_search_item(&a, "5", cmp), "5") == 0);
	assert(strcmp(btree_search_item(&a, "3", cmp), "3") == 0);
	assert(btree_search_item(&a, "42", cmp) == NULL);
	assert(btree_search_item(NULL, "5", cmp) == NULL);
	puts("✅ All tests passed");
}

#endif