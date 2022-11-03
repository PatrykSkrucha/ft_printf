/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:02:04 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/03 16:08:11 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		create_pointer(unsigned long int number);
void	format_handler(va_list args, int *result, const char *format, int *i);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		hex_handler(unsigned long int a, int control);
int		print_unsigned(unsigned long int n);
int		ft_putstr(char *s);

#endif