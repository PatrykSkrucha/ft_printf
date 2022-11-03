/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:10:05 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/03 16:08:26 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_handler(unsigned long int a, int control)
{
	int	counter;

	counter = 0;
	if (a >= 16)
	{
		counter += hex_handler(a / 16, control);
		counter += hex_handler(a % 16, control);
	}
	else if (a < 10)
		counter += ft_putchar(a + '0');
	else
	{
		if (control)
			counter += ft_putchar(a + '7');
		else
			counter += ft_putchar(a + 'W');
	}
	return (counter);
}
