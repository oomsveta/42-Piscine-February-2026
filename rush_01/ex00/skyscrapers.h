/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:18:40 by nwatelle          #+#    #+#             */
/*   Updated: 2026/02/15 09:39:44 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPERS_H
# define SKYSCRAPERS_H
# include <stddef.h>	// provides size_t

struct s_board
{
	unsigned int	*grid;
	unsigned int	*all_clues;
	unsigned int	*clues_top;
	unsigned int	*clues_bot;
	unsigned int	*clues_left;
	unsigned int	*clues_right;
	size_t			size;
};

typedef struct s_board	t_board;

#endif /* SKYSCRAPERS_H */
