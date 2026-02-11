/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:55:49 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/11 16:02:01 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

#include <stddef.h>		// provides NULL
#include "ft_list.h"	// provides t_list

t_list	*ft_list_last(t_list *begin_list)
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

#ifdef TEST

// run with test main:
// clang ft_list_last.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;

	a = (t_list){.data = "1. Head", .next = &b};
	b = (t_list){.data = "2. Node", .next = &c};
	c = (t_list){.data = "3. Tail", .next = NULL};
	assert(ft_list_last(&a) == &c);
	assert(ft_list_last(&c) == &c);
	assert(ft_list_last(NULL) == NULL);
	puts("✅ All tests passed");
}

#endif
