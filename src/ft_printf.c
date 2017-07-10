/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:58:17 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/10 20:39:12 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_printf(const char *format, ...)
{
	size_t			i;
	t_args			args;
	va_list			ap;

	i = 0;
	args = format_string_parser(format);
	if (format)
	{
		va_start(ap, format);
		while (i < args.len)
		{
			ft_putnstr(format, loc_conv(format));
			core(ap, args, i);
			++i;
		}
		va_end(ap);
	}
	return (0);
}