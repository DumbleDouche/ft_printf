/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:58:17 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/10 08:13:48 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_printf(const char *format, ...)
{
	size_t			i;
	t_args			args;
	// va_list			ap;

	i = 0;
	args = format_string_parser(format);
	// if (format)
	// {
	// 	va_start(ap, format);
	// 	while (format)
	// 	{
	// 		// va_arg(ap, contains(INTS, args.list[i].specifier) ? long long:
	// 		// contains());
	// 		++i;
	// 	}
	// 	va_end(ap);
	// }
	return (0);
}
