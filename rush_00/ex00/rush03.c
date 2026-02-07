/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:59:19 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/07 23:06:51 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush_generic(int width, int height, const char style[6]);

/**
 * Example output:
 *
 * ABBBC
 * B   B
 * ABBBC
 */
void	rush(int x, int y)
{
	rush_generic(x, y, "ACACBB");
}
