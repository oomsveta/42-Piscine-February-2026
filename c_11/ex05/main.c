/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:54:17 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 23:25:51 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides EXIT_SUCCESS, NULL

void	ft_add(int a, int b);
void	ft_sub(int a, int b);
void	ft_mul(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);
void	ft_putnbr(int n);
int		ft_atoi(const char *nptr);

static void	(*g_ops[])(int, int) = {
	ft_mod,
	NULL,
	NULL,
	NULL,
	NULL,
	ft_mul,
	ft_add,
	NULL,
	ft_sub,
	NULL,
	ft_div,
};

static void	do_op(int a, int b, char *op)
{
	if (op[0] == '\0' || op[1] != '\0')
	{
		ft_putnbr(0);
		return ;
	}
	if (*op < '%' || *op > '/' || g_ops[*op - '%'] == NULL)
	{
		ft_putnbr(0);
		return ;
	}
	g_ops[*op - '%'](a, b);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		return (EXIT_SUCCESS);
	}
	do_op(ft_atoi(argv[1]), ft_atoi(argv[3]), argv[2]);
}
