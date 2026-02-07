/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:09:51 by pvan-lin           #+#    #+#             */
/*   Updated: 2026/02/07 22:30:20 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush_generic(int width, int height, const char style[6]);

/**
 * Example output:
 *
 * ABBBA
 * B   B
 * CBBBC
 */
void	rush(int x, int y)
{
	rush_generic(x, y, "AACCBB");
}
