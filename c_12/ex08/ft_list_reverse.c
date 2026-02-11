/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:06:20 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/11 18:34:05 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

#include <stddef.h>		// provides NULL
#include "ft_list.h"	// provides t_list

void ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	while (*begin_list != NULL)
	{
		next = (*begin_list)->next;
		(*begin_list)->next = prev;
		prev = (*begin_list);
		(*begin_list) = next;
	}
	*begin_list = prev;
}

#ifdef TEST

// run with test main:
// clang ft_list_reverse.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;
	t_list	*head;

	a = (t_list){.data = "1", .next = &b};
	b = (t_list){.data = "2", .next = &c};
	c = (t_list){.data = "3", .next = NULL};
	head = &a;
	ft_list_reverse(&head);
	assert(((char *)head->data)[0] == '3');
	assert(((char *)head->next->data)[0] == '2');
	assert(((char *)head->next->next->data)[0] == '1');
	puts("✅ All tests passed");
}

#endif
