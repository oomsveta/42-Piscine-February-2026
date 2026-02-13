/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:50:19 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/13 12:03:04 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#endif

#include <stddef.h>		// provides NULL
#include "ft_list.h"	// provides t_list

void	ft_list_remove_if(
	t_list **begin_list,
	void *data_ref,
	int (*cmp)(void *, void *),
	void (*free_fct)(void *)
)
{
	t_list	*current;

	while (*begin_list != NULL)
	{
		current = *begin_list;
		if (cmp(current->data, data_ref) == 0)
		{
			*begin_list = current->next;
			free_fct(current->data);
		}
		else
		{
			begin_list = &current->next;
		}
	}
}

#ifdef TEST

void	noop(void *data)
{
	(void)data;
}

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
// clang ft_list_remove_if.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*head;

	head = NULL;
	ft_list_push_front(&head, "1");
	c = head;
	ft_list_push_front(&head, "2");
	b = head;
	ft_list_push_front(&head, "1");
	a = head;
	ft_list_remove_if(&head, "1", (int (*)())strcmp, noop);
	assert(head == b && b->next == NULL);
	ft_list_remove_if(&head, "2", (int (*)())strcmp, noop);
	assert(head == NULL);
	puts("✅ All tests passed");
}

#endif
