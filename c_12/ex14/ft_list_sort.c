/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:44:26 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/11 18:51:27 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

static void	ft_swap(void **a, void **b)
{
	void	**tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void ft_list_sort(t_list **begin_list, int (*cmp)())
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
