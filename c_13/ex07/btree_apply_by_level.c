/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:32:38 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/17 08:46:45 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// provides malloc, size_t
#include <stdbool.h>	// provides false, true
#include "ft_btree.h"	// provides t_bfs_node, t_btree, t_queue

static size_t	count_nodes(t_btree *root)
{
	if (!root)
	{
		return (0);
	}
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

static void	enqueue(t_queue *queue, t_bfs_node node)
{
	queue->nodes[queue->rear] = node;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->length += 1;
}

static t_bfs_node	dequeue(t_queue *queue)
{
	t_bfs_node	node;

	node = queue->nodes[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->length -= 1;
	return (node);
}

static t_queue	*init_queue(t_queue *queue, size_t capacity)
{
	*queue = (t_queue){0};
	queue->capacity = capacity;
	queue->nodes = malloc(sizeof(t_bfs_node) * capacity);
	if (!queue->nodes)
	{
		return (NULL);
	}
	return (queue);
}

void	btree_apply_by_level(
	t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem)
)
{
	t_queue		queue;
	t_bfs_node	node;
	size_t		current_level;

	if (!root || !init_queue(&queue, (count_nodes(root) + 1) / 2))
		return ;
	enqueue(&queue, (t_bfs_node){root, 0});
	current_level = (size_t)-1;
	while (queue.length > 0)
	{
		node = dequeue(&queue);
		if (node.level != current_level)
		{
			current_level = node.level;
			applyf(node.node->item, node.level, true);
		}
		else
			applyf(node.node->item, node.level, false);
		if (node.node->left)
			enqueue(&queue, (t_bfs_node){node.node->left, node.level + 1});
		if (node.node->right)
			enqueue(&queue, (t_bfs_node){node.node->right, node.level + 1});
	}
	free(queue.nodes);
}

/* 
#include <stdio.h>

void print_node(void *item, int level, int is_first)
{
	printf(
		"%s at level %d %s\n",
		(char *)item,
		level,
		is_first ? " (first in level)" : ""
	);
}

int main(void)
{
	t_btree root, node1, node2, node3, node4;

	root = (t_btree){&node1, &node2, "Root"};
	node1 = (t_btree){&node3, &node4, "Node 1"};
	node2 = (t_btree){NULL, NULL, "Node 2"};
	node3 = (t_btree){NULL, NULL, "Node 3"};
	node4 = (t_btree){NULL, NULL, "Node 4"};

	btree_apply_by_level(&root, print_node);
}
*/
