/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:50:19 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 10:09:15 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>		// provides NULL
#include "ft_list.h"	// provides t_list

void	ft_list_remove_if(
	t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *)
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
