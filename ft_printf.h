/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:02:04 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/01 18:04:09 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		create_pointer(unsigned long int number);
void	format_handler(va_list args, int *result, const char *format, int *i);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		to_hex(long long int a, int control);
int		print_unsigned(unsigned long int n);
int		ft_putstr(char *s);

#endif