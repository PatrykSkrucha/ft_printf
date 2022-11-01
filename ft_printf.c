/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:41:01 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/01 16:55:36 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	to_hex(long long int a, int control)
{
	int	counter;

	counter = 0;
	if (a >= 16)
	{
		counter += to_hex(a / 16, control);
		counter += to_hex(a % 16, control);
	}
	else if (a < 10)
	{
		counter += ft_putchar(a + '0');
	}
	else
	{
		if (control)
			counter += ft_putchar(a + '7');
		else
			counter += ft_putchar(a + 'W');
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		result;
	int		len;
	va_list	args;

	if (!format)
		return (0);
	len = 0;
	while (format[len])
		len++;
	i = 0;
	result = 0;
	va_start(args, format);
	while (i < len)
	{
		format_handler(args, &result, format, &i);
	}
	va_end(args);
	return (result);
}

// int main()
// {
// 	ft_printf("-------");
// 	ft_printf("%s", "ALAABSIU");
// 	printf("%s", "wejmviuwnvew");
// 	ft_printf("-23523523------");
// 	printf("525723-34-66--3426-");
// }