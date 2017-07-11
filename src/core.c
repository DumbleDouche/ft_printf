/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 19:46:23 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 07:44:17 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t			core(va_list l, t_args args, size_t i)
{
	char	c;

	c = type(args, i);
	if (contains(INTS, SPE))
		return (int_types(l, args, i, c));
	else if (SPE == 's')
		return (ft_putstr(va_arg(l, char *)));
	else if (SPE == 'c')
		return (ft_putchar(va_arg(l, long)));
	else
		return (1);
	return (0);
}
