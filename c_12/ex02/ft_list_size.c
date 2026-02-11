/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:49:49 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/11 15:57:55 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

#include <stddef.h>		// provides size_t
#include "ft_list.h"	// provides t_list

int ft_list_size(t_list *begin_list)
{
	size_t	length;

	length = 0;
	while (begin_list)
	{
		length += 1;
		begin_list = begin_list->next;
	}
	return ((int)length);
}

#ifdef TEST

// run with test main:
// clang ft_list_size.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;

	c = (t_list){.data = "1. Head", .next = &b};
	b = (t_list){.data = "2. Node", .next = &a};
	a = (t_list){.data = "3. Tail", .next = NULL};
	assert(ft_list_size(&c) == 3);
	assert(ft_list_size(NULL) == 0);
	puts("✅ All tests passed");
}

#endif
