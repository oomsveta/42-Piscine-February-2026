/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:40:39 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/05 18:23:47 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Quadratic residues mod 16 are 0, 1, 4, and 9.
// Corresponding bitset: 0000 0010 0001 0011 (0x0213 in hex).
#define QUAD_RESIDUES_MOD16 0x0213u

// https://en.wikipedia.org/wiki/Square_root_algorithms

int	ft_sqrt(int n)
{
    if (n < 0 || !((QUAD_RESIDUES_MOD16 >> (n & 15)) & 1))
    {
        return (0);
    }
}
