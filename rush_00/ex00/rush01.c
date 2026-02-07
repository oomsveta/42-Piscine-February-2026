/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:45:56 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/07 22:31:13 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush_generic(int width, int height, const char style[6]);

// no example output, because style contains chars that mess up with comments
void	rush(int x, int y)
{
	rush_generic(x, y, "/\\\\/**");
}
