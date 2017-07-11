/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 21:41:26 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 23:49:00 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

size_t			ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t			ft_wputchar(char c, size_t width, char flag)
{
	if (flag & 1)
	{
		write(1, &c, 1);
		if (width > 1)
			ft_nputchar(' ', width - 1);
	}
	else
	{
		if (width > 1)
			ft_nputchar(' ', width - 1);
		write(1, &c, 1);
	}
	return (width ? width : 1);
}

size_t			ft_nputchar(char c, size_t n)
{
	size_t	i;

	i = n;
	while (n-- > 0)
		write(1, &c, 1);
	return (i);
}

size_t			ft_putnstr(const char *string, size_t size)
{
	if (string)
		write(1, string, size);
	return (size);
}

size_t			ft_putstr(const char *s, size_t width, ssize_t pre, char flag)
{
	ssize_t	n;

	n = ft_strlen(s);
	n = pre != -1 && n > pre ? pre : n;
	if (flag & 1)
	{
		ft_putnstr(s, n);
		if ((size_t)n < width)
			ft_nputchar(' ', width - n);
	}
	else
	{
		if ((size_t)n < width)
			ft_nputchar(' ', width - n);
		ft_putnstr(s, n);
	}
	return ((size_t)n < width ? width : n);
}
