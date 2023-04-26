/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielp <gabrielp@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:34:42 by gabrielp          #+#    #+#             */
/*   Updated: 2023/04/26 02:00:16 by gabrielp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_char(char str, int *ret)
{
	write(1, &str, 1);
	(*ret)++;
}

void	ft_write_string(char *args, int *ret)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*ret) += 6;
		return ;
	}
	else
	{
		while (args[i])
		{
			ft_write_char(args[i], ret);
			i++;
		}
	}
}
