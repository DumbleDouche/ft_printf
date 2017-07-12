/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 07:38:10 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/12 02:04:43 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t			i_shorts(va_list l, t_args args, size_t i)
{
	if (LEN == 1)
	{
		if (SPE == 'u' || TL(SPE) == 'x' || TL(SPE) == 'o')
			return (ft_putnbr_u((_US)va_arg(l, _UI), args, i));
		else
			return (ft_putnbr((_S)va_arg(l, _I), args, i));
	}
	else
	{
		if (SPE == 'u' || TL(SPE) == 'x' || TL(SPE) == 'o')
			return (ft_putnbr_u((_UC)va_arg(l, _UI), args, i));
		else
			return (ft_putnbr((_C)va_arg(l, _I), args, i));
	}
}

size_t			i_ints(va_list l, t_args args, size_t i)
{
	if (SPE == 'u' || TL(SPE) == 'x' || TL(SPE) == 'o')
		return (ft_putnbr_u((_UI)va_arg(l, _UI), args, i));
	else
		return (ft_putnbr((_I)va_arg(l, _I), args, i));
}

size_t			i_longs(va_list l, t_args args, size_t i)
{
	if (LEN == 2)
	{
		if (TL(SPE) == 'u' || TL(SPE) == 'x' || TL(SPE) == 'o')
			return (ft_putnbr_u((_ULL)va_arg(l, _ULL), args, i));
		else
			return (ft_putnbr((_LL)va_arg(l, _LL), args, i));
	}
	else
	{
		if (SPE == 'u' || TL(SPE) == 'x' || TL(SPE) == 'o')
			return (ft_putnbr_u((_ULL)va_arg(l, _ULL), args, i));
		else
			return (ft_putnbr((_LL)va_arg(l, _LL), args, i));
	}
}

size_t			i_intmax(va_list l, t_args args, size_t i)
{
	if (SPE == 'u' || TL(SPE) == 'x' || TL(SPE) == 'o')
		return (ft_putnbr_u((_UM)va_arg(l, _UM), args, i));
	else
		return (ft_putnbr((_M)va_arg(l, _M), args, i));
}

size_t			int_types(va_list l, t_args args, size_t i)
{
	if (SPE == 'U')
		return (i_longs(l, args, i));
	else if (LEN == 0)
		return (i_ints(l, args, i));
	else if (LEN == 1 || LEN == -1)
		return (i_shorts(l, args, i));
	else if (LEN == 2 || LEN == -2)
		return (i_longs(l, args, i));
	else if (LEN == 4 || LEN == 8)
		return (i_intmax(l, args, i));
	else
		return (-1);
}
