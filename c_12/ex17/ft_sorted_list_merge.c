/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:40:37 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/13 12:03:26 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

#include <stddef.h>		// provides NULL
#include "ft_list.h"	// provides t_list

void	ft_sorted_list_merge(
	t_list **begin_list1, t_list *begin_list2, int (*cmp)(void *, void *)
)
{
	t_list	**current;
	t_list	*node_to_insert;

	current = begin_list1;
	while (*current != NULL && begin_list2 != NULL)
	{
		if (cmp((*current)->data, begin_list2->data) > 0)
		{
			node_to_insert = begin_list2;
			begin_list2 = begin_list2->next;
			node_to_insert->next = *current;
			*current = node_to_insert;
		}
		else
		{
			current = &(*current)->next;
		}
	}
	if (begin_list2 != NULL)
	{
		*current = begin_list2;
	}
}

#ifdef TEST

// run with test main:
// clang ft_sorted_list_merge.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;
	t_list	*list1;

	a = (t_list){.data = "1", .next = &b};
	b = (t_list){.data = "5", .next = NULL};
	list1 = &a;
	c = (t_list){.data = "3", .next = NULL};
	ft_sorted_list_merge(&list1, &c, (int (*)())strcmp);
	assert(list1 == &a);
	assert(a.next == &c);
	assert(c.next == &b);
	assert(b.next == NULL);
	puts("✅ All tests passed");
}

#endif
