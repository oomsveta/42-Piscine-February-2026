/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:17:36 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/22 23:18:25 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"

void	free_magnitude(void *magnitude)
{
	if (!magnitude)
	{
		return ;
	}
	free(((t_magnitude *)magnitude)->word_form);
	((t_magnitude *)magnitude)->word_form = NULL;
	free(magnitude);
}

void	free_custom_entry(void *custom_entry)
{
	if (!custom_entry)
	{
		return ;
	}
	free(((t_custom_entry *)custom_entry)->word_form);
	((t_custom_entry *)custom_entry)->word_form = NULL;
	free(((t_custom_entry *)custom_entry)->nbr);
	((t_custom_entry *)custom_entry)->nbr = NULL;
	free(custom_entry);
}
