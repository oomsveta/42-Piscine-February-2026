/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:57:01 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 21:38:45 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"	// provides t_list

t_list	*lst_at(t_list *head, size_t n)
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
