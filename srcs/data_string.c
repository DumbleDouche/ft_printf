/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 11:00:21 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 20:41:26 by rchoquer         ###   ########.fr       */
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
