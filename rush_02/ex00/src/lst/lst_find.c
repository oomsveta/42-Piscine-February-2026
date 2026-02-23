/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:42:11 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 21:10:19 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"	// provides t_list

/**
 * @brief Searches for a node matching the given key in the list.
 *
 * Iterates through the list and compares each node's content with the provided
 * key using the comparison function.
 *
 * @param head  The pointer to the first node of the list.
 * @param key   The value to search for.
 * @param cmp   The comparison function to use. Example: strcmp.
 * @return      A pointer to the first matching node if any, NULL otherwise.
 */
t_list	*lst_find(t_list *head, void *key, int (*cmp)(void *, void *))
{
	while (head != NULL)
	{
		if (cmp(head->data, key) == 0)
		{
			return (head);
		}
		head = head->next;
	}
	return (NULL);
}
