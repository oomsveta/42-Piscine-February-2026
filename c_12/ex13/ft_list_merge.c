/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:40:35 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/12 08:41:50 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>		// provides NULL
#include "ft_list.h"	// provides t_list

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	while (*begin_list1 != NULL)
	{
		begin_list1 = &(*begin_list1)->next;
	}
	*begin_list1 = begin_list2;
}
