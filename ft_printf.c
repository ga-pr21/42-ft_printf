/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielp <gabrielp@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:23:15 by gabrielp          #+#    #+#             */
/*   Updated: 2023/04/26 02:23:07 by gabrielp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_eval_format(char str, va_list *args, int *ret, int *i)
{
	if (str == 'c')
		ft_write_char(va_arg(*args, int), ret);
	else if (str == 's')
		ft_write_string(va_arg(*args, char *), ret);
	else if (str == 'x' || str == 'X')
		ft_hexa(va_arg(*args, unsigned int), ret, str);
	else if (str == 'u')
		ft_unsigned(va_arg(*args, unsigned int), ret);
	else if (str == 'p')
		ft_pointer(va_arg(*args, unsigned long), ret);
	else if (str == 'i' || str == 'd')
		ft_putnbr(va_arg(*args, int), ret);
	else if (str == '%')
		ft_write_char('%', ret);
	else
	{
		ft_write_char('%', ret);
		(*i)--;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_eval_format(str[i], &args, &ret, &i);
			i++;
		}
		else
		{
			ft_write_char((char)str[i], &ret);
			i++;
		}
	}
	va_end(args);
	return (ret);
}
