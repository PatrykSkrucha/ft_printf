/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:41:01 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/01 14:11:32 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

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
		counter = 11;
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

static int	ft_putstr(char *s, int control)
{
	int	len;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		if (control)
			free(s);
		return (6);
	}
	len = (int)ft_strlen(s); //zmienic to
	if (s)
		write(1, s, len);
	if (control)
		free(s);
	return (len);
}

static int	to_hex(long long int a, int control)
{
	int	counter;

	counter = 0;
	if (a > 16)
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


// static int	create_pointer(long long number)
// {
// 	int		counter;
// 	void	*ptr;

// 	ptr = (void*)number;
// 	if (ptr == NULL)
// 		{
// 			write(1, "0x0", 3);
// 			return (3);
// 		}
// 	str = to_hex(number, 0, 1);
// 	str[1] = 'x';
// 	str[0] = '0';
// 	return (str);
// }

static int	print_unsigned(unsigned int n)
{
	char	a;
	int counter;

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



int ft_printf(const char *format, ...)
{
	int a = 0;
	int result = 0;
	if (!format)
		return (0);
	int len = strlen(format); 
	va_list args;
	va_start(args, format);
	while(a < len)
	{
		if(format[a] == '%')
		{
			if (format[a + 1] == 'i' ||format[a + 1] == 'd')
				result += ft_putnbr(va_arg(args, int));
			else if (format[a + 1] == 'c')
				result += ft_putchar(va_arg(args, int));
			else if (format[a + 1] == 's')
				result += ft_putstr(va_arg(args, char *), 0);
			else if (format[a + 1] == 'x')
				result += to_hex(va_arg(args, long long int), 0);	
			else if (format[a + 1] == 'X')
				result += to_hex(va_arg(args, long long int), 1);
			else if (format[a + 1] == '%')
				result += ft_putchar('%');
			else if (format[a + 1] == 'u')
				result += print_unsigned(va_arg(args, unsigned int));
			// else if (format[a + 1] == 'p')
			// 	result += ft_putstr(create_pointer(va_arg(args, long long int)), 1);
			a += 2;
		}
		else
		{
			result += ft_putchar(format[a]);
			a++;
		}
	}
	va_end(args);
	return (result);
}

int main()
{
	int b = 100;
	int *c = &b;
	char *s = NULL;
	// printf("%i",printf("%p", (void*)NULL));
	
// 
	int a = ft_printf("hello%i", b);
	ft_printf("size: 8??? %i", a);
	// printf("%p\n", c);
	// printf("%p", &c);
	// printf("size: %i", a);
	
}

//gcc ft_printf.c ../libft/libft.a -o main && ./main