/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:28:19 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/13 09:12:41 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

#include <stddef.h>		// provides NULL
#include "ft_list.h"	// provides t_list

void	ft_list_foreach_if(
	t_list *begin_list,
	void (*f)(void *),
	void *data_ref,
	int (*cmp)(void *, void *)
)
{
	while (begin_list != NULL)
	{
		if (cmp(begin_list->data, data_ref) == 0)
		{
			f(begin_list->data);
		}
		begin_list = begin_list->next;
	}
}

#ifdef TEST

static void	puts_wrapper(void *data)
{
	puts((char *)data);
}

// run with test main:
// clang ft_list_foreach_if.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;

	a = (t_list){.data = "don't print", .next = &b};
	b = (t_list){.data = "print", .next = &c};
	c = (t_list){.data = "don't print", .next = NULL};
	ft_list_foreach_if(&a, puts_wrapper, "print", (int (*)())strcmp);
}

#endif
