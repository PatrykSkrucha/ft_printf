/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:41:01 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/01 11:43:09 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_putnbr(int n)
{
	char	a;
	int counter;

	counter = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		counter = 11;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		counter += ft_putnbr(-n);
		counter++;
	}
	else if (n > 9)
	{
		counter += ft_putnbr(n / 10);
		counter += ft_putnbr(n % 10);
	}
	else
	{
		a = n + '0';
		write(1, &a, 1);
		counter++;
	}
	return (counter);
}

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr(char *s, int control)
{
	int len;

	len = (int)ft_strlen(s);
	if (s)
		write(1, s, len);
	if(control)
		free(s);
	return (len);
}


static char *to_hex(long long int a, int control, int pointer)
{
	char *str;
	int mem_size;
	long long int temp;

	temp = a;
	mem_size = 0;
	while (temp >= 1)
	{
		temp /= 16;
		mem_size++;
	}
	if (pointer)
		mem_size += 2;
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

static char	*create_pointer(long long number)
{
	char	*str;

	str = to_hex(number, 0, 1);
	str[1] = 'x';
	str[0] = '0';
	return (str);
}

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
				result += ft_putstr(to_hex(va_arg(args, long long int), 0, 0), 1);	
			else if (format[a + 1] == 'X')
				result += ft_putstr(to_hex(va_arg(args, long long int), 1, 0), 1);
			else if (format[a + 1] == '%')
				result += ft_putchar('%');
			else if (format[a + 1] == 'u')
				result += print_unsigned(va_arg(args, unsigned int));
			else if (format[a + 1] == 'p')
				result += ft_putstr(create_pointer(va_arg(args, long long int)), 1);
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

// int main()
// {
// 	int b = 12548;
// 	char *s = NULL;
// 	// ft_printf("%s", (char *)NULL);
// 	write(1, s[0], 1);

// 	// printf("%x\n", b);
// 	// printf("%p\n", c);
// 	// printf("%p", &c);
// 	// printf("size: %i", a);
	
// }

//gcc ft_printf.c ../libft/libft.a -o main && ./main