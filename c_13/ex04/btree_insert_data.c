/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:47:08 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/16 21:32:05 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
