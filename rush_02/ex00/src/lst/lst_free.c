/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:21:35 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 15:25:18 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"	// provides t_list
#include <stdlib.h>	// provides free, NULL

static void	noop(void *ptr)
{
	(void)ptr;
}

void	lst_free(t_list **head, void (*free_fn)(void *))
{
	t_list	*to_free;

	if (free_fn == NULL)
	{
		free_fn = noop;
	}
	while (*head != NULL)
	{
		to_free = *head;
		*head = (*head)->next;
		free_fn(to_free->data);
		to_free->data = NULL;
		free(to_free);
	}
}
