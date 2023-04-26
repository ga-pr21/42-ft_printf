/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielp <gabrielp@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:24:18 by gabrielp          #+#    #+#             */
/*   Updated: 2023/04/26 02:14:50 by gabrielp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_write_char(char str, int *ret);
void	ft_write_string(char *args, int *ret);
void	ft_eval_format(char str, va_list *args, int *ret, int *i);
void	ft_putnbr(int num, int *ret);
void	ft_pointer(unsigned long p, int *ret);
void	ft_hexa(unsigned int x, int *ret, char w_x);
void	ft_unsigned(unsigned int u, int *ret);

#endif