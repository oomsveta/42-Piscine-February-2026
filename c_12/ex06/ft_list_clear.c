/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:37:18 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/11 18:37:46 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"	// provides t_list
#include <stdlib.h>		// provides free, NULL

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*to_free;

	while (begin_list != NULL)
	{
		to_free = begin_list;
		begin_list = begin_list->next;
		free_fct(to_free->data);
		free(to_free);
	}
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
// clang ft_list_clear.c -W{all,extra} -DTEST && valgrind ./a.out
int	main(void)
{
	t_list	*head;

	head = NULL;
	ft_list_push_front(&head, NULL);
	ft_list_push_front(&head, NULL);
	ft_list_push_front(&head, NULL);
	ft_list_clear(head, free);
}

#endif
