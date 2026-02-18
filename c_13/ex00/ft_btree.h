/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:12:02 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 23:00:43 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;
