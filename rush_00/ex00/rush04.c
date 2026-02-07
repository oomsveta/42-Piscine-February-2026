/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:16:08 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/07 23:07:02 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush_generic(int width, int height, const char style[6]);

/*
 * Example output:
 *
 * ABBBC
 * B   B
 * CBBBA
 */
void	rush(int x, int y)
{
	rush_generic(x, y, "ACCABB");
}
