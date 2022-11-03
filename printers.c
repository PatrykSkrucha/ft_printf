/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:34:53 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/03 16:15:43 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	counter;

	counter = 0;
	counter += write(1, &c, 1);
	return (counter);
}

int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		counter += write(1, "-2147483648", 11);
		return (counter);
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
		counter += ft_putchar(n + '0');
	return (counter);
}

int	ft_putstr(char *s)
{
	int	counter;

	counter = 0;
	if (s == NULL)
	{
		counter += write(1, "(null)", 6);
		return (counter);
	}
	while (s[counter])
		counter++;
	if (s)
		write(1, s, counter);
	return (counter);
}

int	print_unsigned(unsigned long int n)
{
	int		counter;

	counter = 0;
	if (n > 9)
	{
		counter += ft_putnbr(n / 10);
		counter += ft_putnbr(n % 10);
	}
	else
		counter += ft_putchar(n + '0');
	return (counter);
}
