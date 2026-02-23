/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_prepend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:22:25 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/21 18:57:33 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"	// provides lst_create_node, t_list

void	*lst_prepend(t_list **head, void *data)
{
	t_list	*new_node;

	new_node = lst_create_node(data);
	if (!new_node)
	{
		return (NULL);
	}
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
