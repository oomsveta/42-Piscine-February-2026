/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:57:01 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/13 10:06:34 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdlib.h>
# include <stdio.h>
#endif

#include "ft_list.h"	// provides t_list
#include <stddef.h>		// provides size_t

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	size_t	i;

	i = 0;
	while (i < nbr && begin_list)
	{
		begin_list = begin_list->next;
		i += 1;
	}
	return (begin_list);
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

static void	ft_list_push_front(t_list **begin_list, void *data)
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

// run with test main:
// clang ft_list_at.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	assert(ft_list_at(head, 0) == NULL);
	assert(ft_list_at(head, 1) == NULL);
	ft_list_push_front(&head, NULL);
	assert(ft_list_at(head, 0) == head);
	ft_list_push_front(&head, NULL);
	assert(ft_list_at(head, 1) == head->next);
	assert(ft_list_at(head, 2) == NULL);
	puts("✅ All tests passed");
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

#endif
