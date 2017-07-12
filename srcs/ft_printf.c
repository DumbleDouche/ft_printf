/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:58:17 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/12 01:19:03 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
		args.printed += ft_putnstr(format, loc_conv(format));
		while (i < args.len)
		{
			args.printed += core(ap, args, i);
			args.printed += ft_putnstr(format + args.list[i].index,
			loc_conv(format + args.list[i].index));
			++i;
		}
		va_end(ap);
	}
	return (args.printed);
}
