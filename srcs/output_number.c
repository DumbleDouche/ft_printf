/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 21:24:03 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 23:55:59 by rchoquer         ###   ########.fr       */
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

size_t		ft_putnbr(intmax_t nb, char c, size_t width, char flag)
{
	size_t				base;
	size_t				digi;
	intmax_t			ret;

	base = get_base(c);
	digi = digits(nb, base);
	ret = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		ret *= -1;
	}
	if (flag & 1)
	{
		ft_putnbr_r(ret, base, c == 'x' ? 0 : 1);
		if (digi < width)
			ft_nputchar(flag & 16 ? '0' : ' ', width - digi);
	}
	else
	{
		if (digi < width)
			ft_nputchar(flag & 16 ? '0' : ' ', width - digi);
		ft_putnbr_r(ret, base, c == 'x' ? 0 : 1);
	}
	return (digi > width ? digi : width);
}

size_t		ft_putnbr_u(uintmax_t nb, char c, size_t width, char flag)
{
	size_t				base;
	size_t				digi;

	base = get_base(c);
	digi = digits(nb, base);
	if (flag & 1)
	{
		ft_putnbr_r(nb, base, c == 'x' ? 0 : 1);
		if (digi < width)
			ft_nputchar(flag & 16 ? '0' : ' ', width - digi);
	}
	else
	{
		if (digi < width)
			ft_nputchar(flag & 16 ? '0' : ' ', width - digi);
		ft_putnbr_r(nb, base, c == 'x' ? 0 : 1);
	}
	return (digi > width ? digi : width);
}
