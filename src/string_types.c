/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:12:29 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 12:02:34 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

// size_t		s_wchar(va_list l, t_args args, size_t i);
// size_t		s_wstr(va_list l, t_args args, size_t i);

size_t		string_types(va_list l, t_args args, size_t i)
{
	if (SPE == 's')
		return (ft_putstr(va_arg(l, char *), WID));
	else if (SPE == 'c')
		return (ft_wputchar(va_arg(l, unsigned int), WID));
	// else if (SPE == 'S')
	// 	return (s_wstr(l, args, i));
	// else if (SPE == 'C')
	// 	return (s_wstr(l, args, i));
	else
		return (0);
}
