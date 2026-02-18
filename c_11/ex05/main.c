/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:54:17 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 13:50:06 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides EXIT_FAILURE, EXIT_SUCCESS, NULL

// could be an enum
#define SUCCESS 1
#define OVERFLOW_ERROR 2
#define UNDERFLOW_ERROR 3

void	ft_add(int a, int b);
void	ft_sub(int a, int b);
void	ft_mul(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);
void	ft_putnbr(int n);
void	ft_puts(const char *str);
int		parse_int(const char *nptr, int *result);

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
	int	a;
	int	b;

	if (argc != 4)
	{
		return (EXIT_SUCCESS);
	}
	if (parse_int(argv[1], &a) != SUCCESS || parse_int(argv[3], &b) != SUCCESS)
	{
		ft_puts("Stop : input doesn't fit in an integer");
		return (EXIT_SUCCESS);
	}
	do_op(a, b, argv[2]);
}
