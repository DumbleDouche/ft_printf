/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 05:04:28 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/12 07:37:26 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		putnbr_e_s_1(t_args args, intmax_t nb, size_t b, size_t i)
{
	size_t		d;
	uintmax_t	ret;

	ret = nb < 0 ? -nb : nb;
	d = digits(nb, b);
	if (nb < 0)
		ft_putchar('-');
	else if (FLA & 2 || FLA & 4)
		ft_putchar((FLA & 2 ? '+' : ' '));
	ft_putnbr_r(ret, b, SPE == 'x' ? 0 : 1);
	if (d < WID)
		ft_nputchar(' ', WID - d);
	return (d);
}

size_t		putnbr_e_s_2(t_args args, intmax_t nb, size_t b, size_t i)
{
	uintmax_t	ret;
	size_t		d;

	ret = nb < 0 ? -nb : nb;
	d = digits(nb, b);
	if (d < WID)
		ft_nputchar(FLA & 16 ? '0' : ' ', WID - d);
	if (nb < 0)
		ft_putchar('-');
	else if (FLA & 2 || FLA & 4)
		ft_putchar((FLA & 2 ? '+' : ' '));
	ft_putnbr_r(ret, b, SPE == 'x' ? 0 : 1);
	return (d);
}

size_t		putnbr_e_u_1(t_args args, uintmax_t nb, size_t b, size_t i)
{
	size_t		d;

	d = udigits(nb, b);
	// if (FLA & 8 && nb != 0)
	// 	hash(SPE);
	ft_putnbr_r(nb, b, SPE == 'x');
	if (d < WID)
		ft_nputchar(' ', WID - d);
	return (d);
}

size_t		putnbr_e_u_2(t_args args, uintmax_t nb, size_t b, size_t i)
{
	size_t		d;

	d = udigits(nb, b);
	if (d < WID)
		ft_nputchar(FLA & 16 ? '0' : ' ', WID - d);
	ft_putnbr_r(nb, b, SPE == 'x' ? 0 : 1);
	return (d);
}

void		hash(unsigned char c)
{
	if (c == 'o')
		ft_putnstr("0", 1);
	else if (c == 'x')
		ft_putnstr("0x", 2);
	else if (c == 'X')
		ft_putnstr("0X", 2);
}
