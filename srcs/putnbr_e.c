/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 05:04:28 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/16 20:26:15 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		putnbr_e_s_1(t_args args, intmax_t nb, size_t b, size_t i)
{
	size_t		d;
	uintmax_t	ret;

	ret = nb < 0 ? -nb : nb;
	d = udigits(nb, b);
	if (nb < 0)
		ft_putchar('-');
	else if (FLA & 2 || FLA & 4)
		ft_putchar(FLA & 2 ? '+' : ' ');
	if (PRE > 0 && (size_t)PRE > d)
		ft_nputchar('0', PRE);
	ft_putnbr_r(ret, b, 0);
	if (d < WID)
		ft_nputchar(' ', WID - d  - ((nb >= 0 && !!(FLA & 2)) - (nb < 0)));
	return (d);
}

size_t		putnbr_e_s_2(t_args args, intmax_t nb, size_t b, size_t i)
{
	uintmax_t	ret;
	size_t		d;
	size_t		size;

	ret = nb < 0 ? -nb : nb;
	d = udigits(ret, b);
	size = COMP((PRE != -1 ? PRE : 0), d) + ((nb >= 0 && !!(FLA & 2)) + (nb < 0));
	if (size < WID)
		ft_nputchar(FLA & 16 ? '0' : ' ', WID - size);
	if (nb < 0)
		ft_putchar('-');
	else if (FLA & 2 || FLA & 4)
		ft_putchar((FLA & 2  && PRE < 0 ? '+' : ' '));
	if (PRE >= 0 && (size_t)PRE > d)
		ft_nputchar('0', PRE - d);
	ft_putnbr_r(ret, b, 0);
	return (size);
}

size_t		putnbr_e_u_1(t_args args, uintmax_t nb, size_t b, size_t i)
{
	size_t		d;
	size_t		size;

	d = udigits(nb, b);
	size = d;
	if (FLA & 8 && nb != 0)
		size += hash(SPE);
	if (PRE > 0 && (size_t)PRE > d)
		size += ft_nputchar('0', PRE - d);
	ft_putnbr_r(nb, b, SPE == 'x' || SPE == 'p');
	if (size < WID)
		ft_nputchar(' ', WID - size);
	return (size);
}

size_t		putnbr_e_u_2(t_args args, uintmax_t nb, size_t b, size_t i)
{
	size_t		d;
	size_t		size;

	d = udigits(nb, b);
	size = d + (((FLA & 8) && TL(SPE != 'u') && (nb != 0)) ? (TL(SPE) == 'x')
	+ 1 : 0) + (PRE > 0 && (size_t)PRE > d ? PRE - d : 0);
	if (size < WID)
		ft_nputchar(FLA & 16 && PRE < 0 ? '0' : ' ', WID - size);
	if (FLA & 8 && nb != 0)
		hash(SPE);
	if (PRE > 0 && (size_t)PRE > d)
		ft_nputchar('0', PRE - d);
	ft_putnbr_r(nb, b, SPE == 'x' || SPE == 'p');
	return (size);
}

int			hash(unsigned char c)
{
	if (c == 'o')
		return (ft_putnstr("0", 1));
	else if (c == 'x')
		return (ft_putnstr("0x", 2));
	else if (c == 'X')
		return (ft_putnstr("0X", 2));
	return (0);
}
