/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:14:37 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/21 17:46:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stddef.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

t_list	*lst_at(t_list *head, size_t n);
t_list	*lst_find(t_list *head, void *key, int (*cmp)(void *, void *));
void	*lst_prepend(t_list **head, void *data);
t_list	*lst_create_node(void *data);
void	lst_free(t_list **head, void (*free_fn)(void *));

#endif
