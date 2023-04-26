/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielp <gabrielp@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:13:19 by gabrielp          #+#    #+#             */
/*   Updated: 2023/04/25 21:22:48 by gabrielp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num, int *ret)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*ret) += 11;
		return ;
	}
	if (num < 0)
	{
		ft_write_char('-', ret);
		ft_putnbr(num * -1, ret);
	}
	else
	{
		if (num > 9)
			ft_putnbr(num / 10, ret);
		ft_write_char(num % 10 + '0', ret);
	}
}

void	ft_pointer(unsigned long p, int *ret)
{
	char	str[25];
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	if (p == 0)
	{
		ft_write_string("(nil)", ret);
		return ;
	}
	(*ret) += 2;
	write(1, "0x", 2);
	while (p != 0)
	{
		str[i] = base[p % 16];
		p = p / 16;
		i++;
	}
	while (i--)
	{
		ft_write_char(str[i], ret);
	}
}

void	ft_hexa(unsigned int x, int *ret, char w_x)
{
	char	str[25];
	char	*base;
	int		i;

	if (w_x == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_write_char('0', ret);
		return ;
	}
	while (x != 0)
	{
		str[i] = base[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_write_char(str[i], ret);
}

void	ft_unsigned(unsigned int u, int *ret)
{
	if (u >= 10)
		ft_unsigned(u / 10, ret);
	ft_write_char(u % 10 + '0', ret);
}
