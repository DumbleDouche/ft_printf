/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 21:24:03 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/10 22:34:28 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <unistd.h>

size_t		ft_putnstr(const char *string, size_t size)
{
	if (string)
		write(1, string, size);
	return (size);
}

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
	long			res;
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

void		ft_putnbr_r(unsigned long n, size_t base)
{
	if (n >= base)
	{
		ft_putnbr_r(n / base, base);
		ft_putnbr_r(n % base, base);
	}
	else
		ft_putchar(HEXU[n]);
}

size_t		ft_putnbr(int nb, size_t base)
{
	unsigned long long	ret;

	ret = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		ret *= -1;
	}
	ft_putnbr_r(ret, base);
	return (digits(nb, base));
}
