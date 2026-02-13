/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:40:35 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/13 10:08:44 by lwicket          ###   ########.fr       */
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

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	while (*begin_list1 != NULL)
	{
		begin_list1 = &(*begin_list1)->next;
	}
	*begin_list1 = begin_list2;
}

#ifdef TEST

// run with test main:
// clang ft_list_merge.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;
	t_list	*head;

	a = (t_list){.next = NULL};
	b = (t_list){.next = NULL};
	c = (t_list){.next = NULL};
	head = &a;
	ft_list_merge(&head, &b);
	assert(head == &a && a.next == &b && b.next == NULL);
	ft_list_merge(&head, NULL);
	assert(b.next == NULL);
	head = NULL;
	ft_list_merge(&head, &c);
	assert(head == &c && c.next == NULL);
	puts("✅ All tests passed");
}

#endif