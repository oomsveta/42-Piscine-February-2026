/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:56:09 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/11 10:01:48 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>	// provides INT_MAX, INT_MIN

void	ft_puts(const char *str);
void	ft_putnbr(int n);

void	ft_add(int a, int b)
{
	if (a > 0 && b > 0 && a > INT_MAX - b)
	{
		ft_puts("Stop : integer overflow");
		return ;
	}
	if (a < 0 && b < 0 && a < INT_MIN - b)
	{
		ft_puts("Stop : integer underflow");
		return ;
	}
	ft_putnbr(a + b);
}

void	ft_sub(int a, int b)
{
	if (a > 0 && b < 0 && a > INT_MAX + b)
	{
		ft_puts("Stop : integer overflow");
		return ;
	}
	if (a < 0 && b > 0 && a < INT_MIN + b)
	{
		ft_puts("Stop : integer underflow");
		return ;
	}
	ft_putnbr(a + b);
}

void	ft_mul(int a, int b)
{
	if (a == 0 || b == 0)
	{
		ft_putnbr(0);
	}
	else if (a > 0 && b > 0 && a > INT_MAX / b)
	{
		ft_puts("Stop : integer overflow");
	}
	else if (a > 0 && b < 0 && b < INT_MIN / a)
	{
		ft_puts("Stop : integer underflow");
	}
	else if (a < 0 && b > 0 && a < INT_MIN / b)
	{
		ft_puts("Stop : integer underflow");
	}
	else if (a < 0 && b < 0 && a < INT_MAX / b)
	{
		ft_puts("Stop : integer overflow");
	}
	else
	{
		ft_putnbr(a * b);
	}
}

void	ft_div(int a, int b)
{
	if (b == 0)
	{
		ft_puts("Stop : division by zero");
		return ;
	}
	if (a == INT_MIN && b == -1)
	{
		ft_puts("Stop : integer overflow");
		return ;
	}
	ft_putnbr(a / b);
}

void	ft_mod(int a, int b)
{
	if (b == 0)
	{
		ft_puts("Stop : modulo by zero");
		return ;
	}
	if (a == INT_MIN && b == -1)
	{
		ft_putnbr(0);
		return ;
	}
	ft_putnbr(a % b);
}
