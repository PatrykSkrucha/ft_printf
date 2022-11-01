/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:41:01 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/01 15:49:06 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		counter += ft_putchar('-');
		counter += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		counter += ft_putnbr(n / 10);
		counter += ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		counter++;
	}
	return (counter);
}

static int	ft_putstr(char *s)
{
	int	len;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = (int)strlen(s); //zmienic to
	if (s)
		write(1, s, len);
	return (len);
}

static int	to_hex(long long int a, int control)
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

static int	convert_pointer(unsigned long int number)
{
	int	counter;

	counter = 0;
	if (number >= 16)
	{
		counter += convert_pointer(number / 16);
		counter += convert_pointer(number % 16);
	}
	else if (number < 10)
	{
		counter += ft_putchar(number + '0');
	}
	else
		counter += ft_putchar(number + 'W');
	return (counter);
}

static int	create_pointer(unsigned long int number)
{
	int		counter;

	counter = 0;
	counter += write(1, "0x", 2);
	counter += convert_pointer(number);
	return (counter);
}

static int	print_unsigned(unsigned long int n)
{
	char	a;
	int		counter;

	counter = 0;
	if (n > 9)
	{
		counter += ft_putnbr(n / 10);
		counter += ft_putnbr(n % 10);
	}
	else
	{
		a = n + '0';
		counter += ft_putchar(a);
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
	len = strlen(format);
	i = 0;
	result = 0;
	va_start(args, format);
	while (i < len)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'i' || format[i + 1] == 'd')
				result += ft_putnbr(va_arg(args, int));
			else if (format[i + 1] == 'c')
				result += ft_putchar(va_arg(args, int));
			else if (format[i + 1] == 's')
				result += ft_putstr(va_arg(args, char *));
			else if (format[i + 1] == 'x')
				result += to_hex(va_arg(args, unsigned int), 0);
			else if (format[i + 1] == 'X')
				result += to_hex(va_arg(args, unsigned int), 1);
			else if (format[i + 1] == '%')
				result += ft_putchar('%');
			else if (format[i + 1] == 'u')
				result += print_unsigned(va_arg(args, unsigned int));
			else if (format[i + 1] == 'p')
				result += create_pointer(va_arg(args, unsigned long int));
			i += 2;
		}
		else
		{
			result += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (result);
}

int main()
{
	int b = 100;
	int c;
	char *s = NULL;
	// printf("%p", (void*)NULL);
	
//  0x10c597f7e 
	// int a = ft_printf("hello%i", b);
	// ft_printf("size: 8??? %i", a);
	// printf("%llu\n", c);
	// ft_printf("%p", (void *)-14523);
	ft_printf("\001\002\007\v\010\f\r\n");
	printf("\001\002\007\v\010\f\r\n");
	// printf("size: %i", a);
	
}

//gcc ft_printf.c ../libft/libft.a -o main && ./main