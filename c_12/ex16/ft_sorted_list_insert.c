/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:40:41 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/13 09:41:55 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#endif

#include "ft_list.h"	// provides ft_create_elem, t_list
#include <stddef.h>		// provides NULL

void	ft_sorted_list_insert(
	t_list **begin_list,
	void *data,
	int (*cmp)(void *, void *)
)
{
	t_list	*new_node;
	t_list	**current;

	new_node = ft_create_elem(data);
	if (!new_node)
	{
		return ;
	}
	current = begin_list;
	while (*current != NULL && cmp((*current)->data, data) < 0)
	{
		current = &(*current)->next;
	}
	new_node->next = *current;
	*current = new_node;
}

#ifdef TEST

t_list	*ft_create_elem(void *data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		return (NULL);
	}
	*new_node = (t_list){.data = data, .next = NULL};
	return (new_node);
}

// run with test main:
// clang ft_sorted_list_insert.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	ft_sorted_list_insert(&head, "3", (int (*)())strcmp);
	ft_sorted_list_insert(&head, "1", (int (*)())strcmp);
	ft_sorted_list_insert(&head, "4", (int (*)())strcmp);
	ft_sorted_list_insert(&head, "2", (int (*)())strcmp);
	assert(strcmp(head->data, "1") == 0);
	assert(strcmp(head->next->data, "2") == 0);
	assert(strcmp(head->next->next->data, "3") == 0);
	assert(strcmp(head->next->next->next->data, "4") == 0);
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	puts("✅ All tests passed");
}

#endif
