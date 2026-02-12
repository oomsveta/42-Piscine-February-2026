/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:42:11 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 10:08:12 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

#include <stddef.h>		// provides NULL
#include "ft_list.h"	// provides t_list

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list != NULL)
	{
		if (cmp(begin_list->data, data_ref) == 0)
		{
			return (begin_list);
		}
		begin_list = begin_list->next;
	}
	return (NULL);
}

#ifdef TEST

// run with test main:
// clang ft_list_find.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;

	a = (t_list){.data = "Shrek", .next = &b};
	b = (t_list){.data = "Morshu", .next = &c};
	c = (t_list){.data = "Gwonam", .next = NULL};
	assert(ft_list_find(&a, "Morshu", (int (*)())strcmp) == &b);
	assert(ft_list_find(&a, "HELP", (int (*)())strcmp) == NULL);
	puts("✅ All tests passed");
}

#endif
