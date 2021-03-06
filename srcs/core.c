/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 19:46:23 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 23:39:25 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t			core(va_list l, t_args args, size_t i)
{
	if (contains(INTS, SPE))
		return (int_types(l, args, i));
	else if (contains(STRS, SPE))
		return (string_types(l, args, i));
	else if (contains(SPECIAL, SPE))
		return (special_types(l, args, i));
	else
		return (ft_nputchar(' ', WID - 1));
}
