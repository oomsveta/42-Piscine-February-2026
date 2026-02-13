/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:17:53 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/13 10:09:49 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdlib.h>
# include <stdio.h>
#endif

#include <stddef.h>		// NULL
#include "ft_list.h"	// ft_create_elem, t_list

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

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*head;
	int		i;

	i = 0;
	while (i < size)
	{
		ft_list_push_front(&head, strs[i]);
		i += 1;
	}
	return (head);
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
// clang ft_list_push_strs.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	const char	*strings[] = {"a", "b", "c"};
	t_list		*head;
	t_list		*tmp;

	head = ft_list_push_strs(3, (char **)strings);
	assert(head->data == strings[2]);
	assert(head->next->data == strings[1]);
	assert(head->next->next->data == strings[0]);
	puts("✅ All tests passed");
	while (head)
	{
		tmp = (t_list *)head;
		head = head->next;
		free(tmp);
	}
}

#endif
