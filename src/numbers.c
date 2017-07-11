/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 21:24:03 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 07:52:31 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <unistd.h>

size_t		digits(long nbr, unsigned int base)
{
	size_t	i;

	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

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

size_t		ft_putnbr(intmax_t nb, char c)
{
	size_t				base;
	uintmax_t			ret;

	base = 0;
	if (TL(c) == 'o')
		base = 8;
	else if (TL(c) == 'x')
		base = 16;
	else
		base = 10;
	ret = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		ret *= -1;
	}
	ft_putnbr_r(ret, base, c == 'x' ? 0 : 1);
	return (digits(nb, base));
}

size_t		ft_putnbr_u(uintmax_t nb, char c)
{
	size_t				base;

	base = 0;
	if (TL(c) == 'o')
		base = 8;
	else if (TL(c) == 'x')
		base = 16;
	else
		base = 10;
	ft_putnbr_r(nb, base, c == 'x' ? 0 : 1);
	return (digits(nb, base));
}
