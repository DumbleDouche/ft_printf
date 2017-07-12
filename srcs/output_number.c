/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_number.SPE                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 21:24:03 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/12 02:05:40 by rchoquer         ###   ########.fr       */
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

void		ft_putnbr_r(uintmax_t n, size_t base, char l)
{
	if (n >= base)
	{
		ft_putnbr_r(n / base, base, l);
		ft_putnbr_r(n % base, base, l);
	}
	else
		ft_putchar(l ? HEXU[n] : HEXL[n]);
}

size_t		ft_putnbr(intmax_t nb, t_args args, size_t i)
{
	size_t				base;
	size_t				digi;
	intmax_t			ret;

	base = get_base(SPE);
	digi = digits(nb, base);
	ret = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		ret *= -1;
	}
	if (FLA & 1)
	{
		ft_putnbr_r(ret, base, SPE == 'x' ? 0 : 1);
		if (digi < WID)
			ft_nputchar(FLA & 16 ? ' ' : ' ', WID - digi);
	}
	else
	{
		if (digi < WID)
			ft_nputchar(FLA & 16 ? '0' : ' ', WID - digi);
		ft_putnbr_r(ret, base, SPE == 'x' ? 0 : 1);
	}
	return (digi > WID ? digi : WID);
}

size_t		ft_putnbr_u(uintmax_t nb, t_args args, size_t i)
{
	size_t				base;
	size_t				digi;

	base = get_base(SPE);
	digi = udigits(nb, base);
	if (FLA & 1)
	{
		ft_putnbr_r(nb, base, SPE == 'x' ? 0 : 1);
		if (digi < WID)
			ft_nputchar(FLA & 16 ? ' ' : ' ', WID - digi);
	}
	else
	{
		if (digi < WID)
			ft_nputchar(FLA & 16 ? '0' : ' ', WID - digi);
		ft_putnbr_r(nb, base, SPE == 'x' ? 0 : 1);
	}
	return (digi > WID ? digi : WID);
}
