/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:03:05 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/11 16:17:19 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
#endif

#include <stddef.h>		// provides NULL
#include "ft_list.h"	// provides t_list

static t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list)
	{
		return (NULL);
	}
	while (begin_list->next)
	{
		begin_list = begin_list->next;
	}
	return (begin_list);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*tail;

	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	tail = ft_list_last(*begin_list);
	tail->next = ft_create_elem(data);
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
// clang ft_list_push_back.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	node;
	t_list	*head;

	node = (t_list){.data = "1. Shrek", .next = NULL};
	head = &node;
	ft_list_push_back(&head, (void *)"2. New tail");
	assert(head->data == node.data);
	assert(strcmp(head->next->data, "2. New tail") == 0);
	free(ft_list_last(head));
	head = NULL;
	ft_list_push_back(&head, (void *)"1. New tail");
	assert(strcmp(head->data, "1. New tail") == 0);
	assert(head->next == NULL);
	free(ft_list_last(head));
	puts("✅ All tests passed");
}

#endif
