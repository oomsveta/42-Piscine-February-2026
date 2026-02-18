/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:47:08 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 17:02:38 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#endif

#include "ft_btree.h"	// provides btree_create_node, t_btree

void	btree_insert_data(
	t_btree **root, void *item, int (*cmpf)(void *, void *)
)
{
	while (*root)
	{
		if (cmpf(item, (*root)->item) < 0)
		{
			root = &((*root)->left);
		}
		else
		{
			root = &((*root)->right);
		}
	}
	*root = btree_create_node(item);
}

#ifdef TEST

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

int	cmp(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

// clang btree_insert_data.c -W{all,extra,error} -DTEST && ./a.out
int	main(void)
{
	t_btree	*root;

	root = NULL;
	btree_insert_data(&root, "5", cmp);
	assert(root != NULL);
	assert(strcmp(root->item, "5") == 0);
	assert(root->left == NULL);
	assert(root->right == NULL);
	btree_insert_data(&root, "3", cmp);
	assert(root->left != NULL);
	assert(strcmp(root->left->item, "3") == 0);
	btree_insert_data(&root, "7", cmp);
	assert(root->right != NULL);
	assert(strcmp(root->right->item, "7") == 0);
	btree_insert_data(&root, "1", cmp);
	assert(root->left->left != NULL);
	assert(strcmp(root->left->left->item, "1") == 0);
	btree_insert_data(&root, "5", cmp);
	assert(root->right->left != NULL);
	assert(strcmp(root->right->left->item, "5") == 0);
	puts("✅ All tests passed");
}

#endif