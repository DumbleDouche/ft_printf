/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 21:24:03 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/26 00:42:13 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	ft_atoi(const char *str)
{
	long long		res;
	unsigned char	isneg;

	isneg = 0;
	res = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r'
	|| *str == '\v' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			isneg = 1;
		str++;
	}
	while (*str && *str >= 48 && *str <= 57)
	{
		res *= 10;
		res += (int)*str - 48;
		str++;
	}
	(isneg) ? (res *= -1) : res;
	return (res);
}

#include <stdio.h>

void		ft_putnbr_r(uintmax_t n, size_t base, char l)
{
	if (n >= base)
	{
		ft_putnbr_r(n / base, base, l);
		ft_putnbr_r(n % base, base, l);
	}
	else
		ft_putchar(l ? HEXL[n] : HEXU[n]);
}

size_t		ft_putnbr(intmax_t nb, t_args args, size_t i)
{
	size_t				base;
	size_t				digi;

	base = get_base(SPE);
	digi = digits(nb, base);
	if (FLA & 1)
		digi = putnbr_e_s_1(args, nb, base, i);
	else
		digi = putnbr_e_s_2(args, nb, base, i);
	return ((digi > WID ? digi + ((FLA & 2 || FLA & 4) && nb >= 0): WID));
}

size_t		ft_putnbr_u(uintmax_t nb, t_args args, size_t i)
{
	size_t				base;
	size_t				digi;

	base = get_base(SPE);
	digi = 0;
	if (FLA & 1)
		digi = putnbr_e_u_1(args, nb, base, i);
	else
		digi = putnbr_e_u_2(args, nb, base, i);
	return ((digi > WID ? digi : WID));
}
