/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:52:37 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 09:54:38 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <assert.h>
# include <stdio.h>
#endif

#include "ft_list.h"	// provides t_list
#include <stddef.h>		// provides size_t

static void	ft_swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static size_t	ft_list_size(t_list *head)
{
	size_t	length;

	length = 0;
	while (head)
	{
		length += 1;
		head = head->next;
	}
	return (length);
}

static t_list	*ft_list_at(t_list *head, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && head)
	{
		head = head->next;
		i += 1;
	}
	return (head);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	const size_t	size = ft_list_size(begin_list);
	const size_t	mid = size / 2;
	size_t			i;
	t_list			*mirror;
	t_list			*current;

	i = 0;
	current = begin_list;
	while (i < mid)
	{
		mirror = ft_list_at(begin_list, size - 1 - i);
		ft_swap(&current->data, &mirror->data);
		current = current->next;
		i += 1;
	}
}

#ifdef TEST

// run with test main:
// clang ft_list_reverse_fun.c -W{all,extra} -DTEST && ./a.out
int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;
	t_list	d;

	a = (t_list){.data = "1", .next = &b};
	b = (t_list){.data = "2", .next = &c};
	c = (t_list){.data = "3", .next = &d};
	d = (t_list){.data = "4", .next = NULL};
	ft_list_reverse_fun(&a);
	assert(((char *)ft_list_at(&a, 0)->data)[0] == '4');
	assert(((char *)ft_list_at(&a, 1)->data)[0] == '3');
	assert(((char *)ft_list_at(&a, 2)->data)[0] == '2');
	assert(((char *)ft_list_at(&a, 3)->data)[0] == '1');
	puts("✅ All tests passed");
}

#endif
