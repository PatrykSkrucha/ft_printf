/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:27:07 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/01 16:50:31 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_number(unsigned long int number)
{
	int	counter;

	counter = 0;
	if (number >= 16)
	{
		counter += convert_number(number / 16);
		counter += convert_number(number % 16);
	}
	else if (number < 10)
	{
		counter += ft_putchar(number + '0');
	}
	else
		counter += ft_putchar(number + 'W');
	return (counter);
}

int	create_pointer(unsigned long int number)
{
	int		counter;

	counter = 0;
	counter += write(1, "0x", 2);
	counter += convert_number(number);
	return (counter);
}
