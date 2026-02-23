/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:08:38 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 21:33:12 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include "list.h"

typedef struct s_dict
{
	char	*ones[20];
	char	*tens[11];
	t_list	*magnitudes;
	t_list	*customs;
}	t_dict;

typedef struct s_magnitude
{
	size_t	length;
	char	*word_form;
}	t_magnitude;

typedef struct s_custom_entry
{
	char	*nbr;
	char	*word_form;
}	t_custom_entry;

int		custom_entry_cmp(void *custom_entry, void *str);
int		magnitude_cmp(void *magnitude, void *len);
int		custom_from_int_cmp(void *custom_entry, void *val);
void	free_magnitude(void *magnitude);
void	free_custom_entry(void *custom_entry);
int		check_dict(t_dict *dict);

#endif
