/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 22:47:16 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/12 04:52:07 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static inline void	setup_arg(t_arg *arg)
{
	arg->index = 0;
	arg->width = 1;
	arg->precision = -1;
	arg->flags = 0;
	arg->length = 0;
	arg->specifier = 0;
}

t_args				setup_args(size_t n)
{
	size_t		i;
	t_args		args;

	i = 0;
	args.len = n;
	args.printed = 0;
	args.list = (t_arg*)MALLOC(sizeof(t_arg), n);
	while (i < n)
	{
		setup_arg(&(args.list[i]));
		++i;
	}
	return (args);
}
