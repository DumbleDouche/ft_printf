/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 07:38:10 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 08:08:34 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t			c_shorts(va_list l, t_args args, size_t i, char c)
{
	if (LEN == 1)
	{
		if (c == 1)
			return (ft_putnbr_u((_US)va_arg(l, _UI), SPE));
		else
			return (ft_putnbr((_S)va_arg(l, _I), SPE));
	}
	else
	{
		if (c == 1)
			return (ft_putnbr_u((_UC)va_arg(l, _UI), SPE));
		else
			return (ft_putnbr((_C)va_arg(l, _I), SPE));
	}
}

size_t			c_ints(va_list l, t_args args, size_t i, char c)
{
	if (c == 1)
		return (ft_putnbr_u((_UI)va_arg(l, _UI), SPE));
	else
		return (ft_putnbr((_I)va_arg(l, _I), SPE));
}

size_t			c_longs(va_list l, t_args args, size_t i, char c)
{
	if (LEN == 2)
	{
		if (c == 1)
			return (ft_putnbr_u((_UL)va_arg(l, _UL), SPE));
		else
			return (ft_putnbr((_L)va_arg(l, _L), SPE));
	}
	else
	{
		if (c == 1)
			return (ft_putnbr_u((_ULL)va_arg(l, _ULL), SPE));
		else
			return (ft_putnbr((_LL)va_arg(l, _LL), SPE));
	}
}

size_t			c_intmax(va_list l, t_args args, size_t i, char c)
{
	if (c == 1)
		return (ft_putnbr_u((_UM)va_arg(l, _UM), SPE));
	else
		return (ft_putnbr((_M)va_arg(l, _M), SPE));
}

size_t			int_types(va_list l, t_args args, size_t i, char c)
{
	if (LEN == 0)
		return (c_ints(l, args, i, c));
	else if (LEN == 1 || LEN == -1)
		return (c_shorts(l, args, i, c));
	else if (LEN == 2 || LEN == -2)
		return (c_longs(l, args, i, c));
	else if (LEN == 4 || LEN == 8)
		return (c_intmax(l, args, i, c));
	else
		return (-1);
}
