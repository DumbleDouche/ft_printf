/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 05:35:01 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 10:13:54 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		type(t_args args, size_t i)
{
	char	c;

	if (SPE == 'd' || SPE == 'i')
		c = 0b00000000;
	else if (SPE == 'u' || TL(SPE) == 'x' || TL(SPE) == 'o')
		c = 0b00000001;
	else if (TL(SPE) == 'c')
		c = (SPE == 'C') ? 0b10000010 : 0b00000010;
	else if (TL(SPE) == 's')
		c = (SPE == 'S') ? 0b10000100 : 0b00000100;
	else if (TL(SPE) == 'g')
		c = (SPE == 'G') ? 0b10001000 : 0b00001000;
	else if (SPE == 'p')
		c = 0b00010000;
	else if (SPE == '%')
		c = 0b00100000;
	else
		c = 0b11111111;
	return (c);
}
