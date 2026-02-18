/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <louis.wicket@protonmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:56:09 by lwicket           #+#    #+#             */
/*   Updated: 2026/02/18 23:07:49 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_puts(const char *str);
void	ft_putnbr(int n);

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_mul(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_div(int a, int b)
{
	if (b == 0)
	{
		ft_puts("Stop : division by zero");
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
	ft_putnbr(a % b);
}
