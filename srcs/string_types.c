/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:12:29 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 23:36:25 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		string_types(va_list l, t_args args, size_t i)
{
	if (SPE == 's')
		return (ft_putstr(va_arg(l, char *), WID, PRE, FLA));
	else if (SPE == 'c')
		return (ft_wputchar(va_arg(l, unsigned int), WID, FLA));
	else
		return (0);
}
