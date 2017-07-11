/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:52:53 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 12:01:46 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t		special_types(va_list l, t_args args, size_t i)
{
	if (SPE == 'p')
		return (ft_putnstr("0x", 2) + ft_putnbr(va_arg(l, _UL), 'x', WID));
	else if (SPE == '%')
		return (ft_putchar('%'));
	else
		return (0);
}
