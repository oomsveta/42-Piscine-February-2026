/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:50:19 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/13 10:08:31 by lwicket          ###   ########.fr       */
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

void	ft_list_remove_if(
	t_list **begin_list,
	void *data_ref,
	int (*cmp)(void *, void *),
	void (*free_fct)(void *)
)
{
	t_list	*current;

	while (*begin_list != NULL)
	{
		current = *begin_list;
		if (cmp(current->data, data_ref) == 0)
		{
			*begin_list = current->next;
			free_fct(current->data);
		}
		else
		{
			begin_list = &current->next;
		}
	}
}

#ifdef TEST

void	noop(void *data)
{
	(void)data;
}

// run with test main:
// clang ft_list_remove_if.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;
	t_list	*head;

	a = (t_list){.data = "1", .next = &b};
	b = (t_list){.data = "2", .next = &c};
	c = (t_list){.data = "1", .next = NULL};
	head = &a;
	ft_list_remove_if(&head, "1", (int (*)())strcmp, noop);
	assert(head == &b && b.next == NULL);
	ft_list_remove_if(&head, "2", (int (*)())strcmp, noop);
	assert(head == NULL);
	puts("✅ All tests passed");
}

#endif
