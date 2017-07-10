/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 05:35:01 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/10 20:40:31 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		type(t_args args, size_t index)
{
	// printf("type: |%c| index: |%zu|\n", args.list[index].specifier, index);
	if (contains(INTS, args.list[index].specifier))
		return ('d');
	return (0);
}