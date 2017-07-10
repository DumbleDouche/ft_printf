/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 19:46:23 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/10 20:18:25 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			core(va_list alist, t_args args, size_t index)
{
	if (type(args, index) == 'd')
		ft_putnbr(va_arg(alist, int));
	return (0);
}