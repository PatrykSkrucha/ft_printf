/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:27:07 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/03 16:08:48 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	create_pointer(unsigned long int number)
{
	int		counter;

	counter = 0;
	counter += write(1, "0x", 2);
	counter += hex_handler(number, 0);
	return (counter);
}
