/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:30:16 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 08:42:42 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <stdio.h>
#endif

#include <stddef.h>		// provides NULL
#include "ft_list.h"	// provides t_list

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != NULL)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}

#ifdef TEST

// run with test main:
// clang ft_list_foreach.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;

	a = (t_list){.data = "3. Tail", .next = NULL};
	b = (t_list){.data = "2. Node", .next = &a};
	c = (t_list){.data = "1. Head", .next = &b};
	ft_list_foreach(&c, (void (*)(void *))puts);
}

#endif
