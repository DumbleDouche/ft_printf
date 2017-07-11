/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 21:41:26 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 04:16:13 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <unistd.h>

size_t			ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t			ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

size_t			ft_putnstr(const char *string, size_t size)
{
	if (string)
		write(1, string, size);
	return (size);
}

size_t			ft_putstr(const char *s)
{
	return (ft_putnstr(s, ft_strlen(s)));
}

unsigned char	ft_tolower(unsigned char c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
