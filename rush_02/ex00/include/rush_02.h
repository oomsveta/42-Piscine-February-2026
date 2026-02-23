/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:27:40 by ldeutsch          #+#    #+#             */
/*   Updated: 2026/02/22 23:09:36 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <stdbool.h>
# include <stddef.h>
# include "dict.h"
# include "list.h"
# include "parsing.h"
# include "utils.h"

# define DICT_FILENAME "numbers.dict"

void			repl(t_dict *dict);
unsigned int	next_triad(const char **nptr);
void			number_to_words(t_dict *dict, const char *nptr);
bool			validate_number(const char *str);
char			*get_tens(t_dict *dict, unsigned int n);
char			*get_magnitude(t_dict *dict, const char *nptr);
char			*get_custom_entry(t_dict *dict, const char *nptr);
char			*get_ones(t_dict *dict, unsigned int n);
void			append_word(char *str, bool *is_first);
void			print_sub_100(t_dict *dict, unsigned int n, bool *is_first);

#endif
