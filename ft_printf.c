/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:41:01 by pskrucha          #+#    #+#             */
/*   Updated: 2022/10/31 14:14:04 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

static char *to_hex(int a, int control)
{
	char *str;
	int mem_size;
	int temp;

	temp = a;
	mem_size = 0;
	while (temp >= 1)
	{
		temp /= 16;
		mem_size++;
	}
	str = (char*)malloc(sizeof(char) * (mem_size + 1));
	if (!str)
		return (NULL);
	str[mem_size] = '\0';
	while (a >= 1)
	{
		mem_size--;
		temp = a % 16;
		if (temp < 10)
			str[mem_size] = temp + '0';
		else
		{
			if (control)
				str[mem_size] = temp + '7';
			else
				str[mem_size] = temp + 'W';
		}

		a /= 16;
	}
	return (str);
}


void	print_unsigned(unsigned int n)
{
	char	a;

	if (n > 9)
	{
		ft_putnbr_fd(n / 10, 1);
		ft_putnbr_fd(n % 10, 1);
	}
	else
	{
		a = n + '0';
		write(1, &a, 1);
	}
}

int ft_printf(const char *format, ...)
{
	int a = 0;
	int result = 0;
	int len = strlen(format); 
	va_list args;
	va_start(args, format);
	while(a < len)
	{
		if(format[a] == '%')
		{
			if (format[a + 1] == 'i' ||format[a + 1] == 'd')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (format[a + 1] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (format[a + 1] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (format[a + 1] == 'x')
				ft_putstr_fd(to_hex(va_arg(args, int), 0), 1);	
			else if (format[a + 1] == 'X')
				ft_putstr_fd(to_hex(va_arg(args, int), 1), 1);				
			else if (format[a + 1] == '%')
				ft_putchar_fd('%', 1);
			else if (format[a + 1] == 'u')
				print_unsigned(va_arg(args, unsigned int));
				
			a += 2;
		}
		else
		{
			ft_putchar_fd(format[a], 1);
			a++;
		}
	}
	va_end(args);

	return (a);
}

int main()
{
	unsigned int a = 10;
	// int *b = &a;
	
	// printf("%p\n", &b);
	
	printf("%u\n", a);
	ft_printf("%u\n", a);
	// to_hex(a);
	// ft_printf("aaaa\n%i\n tu jest cos innego a tu jest oj string: %s\n\n", a, s);
	// printf("aaaa\n%i\n tu jest cos innego a tu jest oj string: %s\n\n", a, s);
}

//gcc ft_printf.c ../libft/libft.a -o main && ./main