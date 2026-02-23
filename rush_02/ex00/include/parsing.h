/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:15:46 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 21:36:17 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>
# include "dict.h"

typedef enum e_parsing_status
{
	SYNTAX_ERROR = -3,
	DUPLICATE_ERROR = -2,
	MALLOC_FAILURE = -1,
	SUCCESS = 0,
	WRONG_NUMBER_TYPE = 1,
}	t_parsing_status;

char				*read_line(int fd);
bool				is_ones(const char *entry, size_t nbr_len);
bool				is_tens(const char *entry, size_t nbr_len);
bool				is_magnitudes(const char *entry, size_t nbr_len);
t_parsing_status	parse_dict_entry(const char *entry, t_dict *dict);

#endif
