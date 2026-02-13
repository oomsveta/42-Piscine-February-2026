/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:44:26 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/13 10:05:41 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
# include <string.h>
#endif

#include <stddef.h>		// provides NULL
#include "ft_list.h"	// provides t_list

static void	ft_swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *))
{
	t_list	*current;
	t_list	*next;

	current = *begin_list;
	while (current != NULL)
	{
		next = current->next;
		while (next != NULL)
		{
			if (cmp(current->data, next->data) > 0)
			{
				ft_swap(&current->data, &next->data);
			}
			next = next->next;
		}
		current = current->next;
	}
}

#ifdef TEST

// run with test main:
// clang ft_list_sort.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;
	t_list	*head;

	a = (t_list){.data = "3", .next = &b};
	b = (t_list){.data = "1", .next = &c};
	c = (t_list){.data = "2", .next = NULL};
	head = &a;
	ft_list_sort(&head, (int (*)(void *, void *))strcmp);
	assert(strcmp(head->data, "1") == 0);
	assert(strcmp(head->next->data, "2") == 0);
	assert(strcmp(head->next->next->data, "3") == 0);
	puts("✅ All tests passed");
}

#endif
