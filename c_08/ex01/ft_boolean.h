/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:54:04 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/08 00:07:26 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>		// provides EXIT_SUCCESS
#include <stdbool.h>	// provides false, true

#define EVEN(x) ((x) % 2 == 0)
#define TRUE true
#define FALSE false
#define SUCCESS EXIT_SUCCESS
#define EVEN_MSG "I have an even number of arguments."
#define ODD_MSG "I have an odd number of arguments."
