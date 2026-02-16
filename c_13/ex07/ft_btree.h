/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:12:02 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/16 20:29:12 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;

typedef struct s_bfs_node
{
	t_btree	*node;
	size_t	level;
}	t_bfs_node;

typedef struct s_queue
{
	t_bfs_node	*nodes;
	size_t		front;
	size_t		rear;
	size_t		capacity;
	size_t		length;
}	t_queue;

t_btree	*btree_create_node(void *item);
