/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: l34k <l34k@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 23:16:18 by l34k              #+#    #+#             */
/*   Updated: 2017/07/12 23:16:40 by l34k             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t			ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

unsigned char	ft_tolower(unsigned char c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
