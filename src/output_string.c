/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 21:41:26 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 12:03:33 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <unistd.h>

size_t			ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t			ft_wputchar(char c, size_t width)
{
	if (width > 1)
		ft_nputchar(' ', width - 1);
	write(1, &c, 1);
	return (width);
}

size_t			ft_nputchar(char c, size_t n)
{
	while (n-- > 0)
		write(1, &c, 1);
	return (0);
}

size_t			ft_putnstr(const char *string, size_t size)
{
	if (string)
		write(1, string, size);
	return (size);
}

size_t			ft_putstr(const char *s, size_t width)
{
	size_t	n;

	n = ft_strlen(s);
	if (n < width)
		ft_nputchar(' ', width - n);
	ft_putnstr(s, n);
	return (n < width ? width : n);
}
