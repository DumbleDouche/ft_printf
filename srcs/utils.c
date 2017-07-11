/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 21:43:44 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/12 00:04:11 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		digits(intmax_t nbr, unsigned int base)
{
	size_t	i;

	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	else if (nbr == 0)
		return (1);
	while (nbr)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

size_t		udigits(uintmax_t nbr, unsigned int base)
{
	size_t	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

size_t		get_base(char c)
{
	if (TL(c) == 'o')
		return (8);
	else if (TL(c) == 'x')
		return (16);
	else
		return (10);
}
