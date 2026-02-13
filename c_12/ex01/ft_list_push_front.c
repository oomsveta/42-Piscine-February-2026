/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:22:25 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/13 08:57:19 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#endif

#include "ft_list.h"	// provides ft_create_elem, t_list

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_node;

	new_node = ft_create_elem(data);
	if (!new_node)
	{
		return ;
	}
	new_node->next = *begin_list;
	*begin_list = new_node;
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
// clang ft_list_push_front.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	node;
	t_list	*head;

	node = (t_list){.data = "1. Shrek", .next = NULL};
	head = &node;
	ft_list_push_front(&head, (void *)"0. New head");
	assert(strcmp(head->data, "0. New head") == 0);
	assert(strcmp(head->next->data, "1. Shrek") == 0);
	free(head);
	head = NULL;
	ft_list_push_front(&head, (void *)"0. New head");
	assert(strcmp(head->data, "0. New head") == 0);
	assert(head->next == NULL);
	free(head);
	puts("✅ All tests passed");
}

#endif
