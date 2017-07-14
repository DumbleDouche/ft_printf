/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:52:53 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/14 19:46:57 by l34k             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		special_types(va_list l, t_args args, size_t i)
{
	if (SPE == 'p')
	{
		return (ft_putnstr("0x", 2) + ft_putnbr_u(va_arg(l, _UL), args, i));
	}
	if (SPE == '%')
		return (ft_wputchar('%', WID, FLA));
	else
		return (0);
}
