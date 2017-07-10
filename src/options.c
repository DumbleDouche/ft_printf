/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 04:25:20 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/10 09:03:13 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

unsigned char		flag(const char *s, size_t *i)
{
	unsigned char	f;

	f = 0;
	while (s[*i] && (s[*i] == '-' || s[*i] == '+' || s[*i] == ' '
	|| s[*i] == '#' || s[*i] == '0'))
	{
		if (s[*i] == '-')
			f |= 0b00000001;
		else if (s[*i] == '+')
			f |= 0b00000010;
		else if (s[*i] == ' ')
			f |= 0b00000100;
		else if (s[*i] == '#')
			f |= 0b00001000;
		else if (s[*i] == '0')
			f |= 0b00010000;
		++(*i);
	}
	return (f);
}

unsigned char		length(const char *s, size_t *i)
{
	unsigned char	f;

	f = 0;
	while (s[*i] && (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'j'
	|| s[*i] == 'z'))
	{
		if (s[*i] == 'h')
			f |= f | 1 ? 0b00000010 : 0b00000001;
		else if (s[*i] == 'l')
			f |= f | 4 ? 0b00001000 : 0b00000100;
		else if (s[*i] == 'j')
			f |= 0b01000000;
		else if (s[*i] == 'z')
			f |= 0b10000000;
		++(*i);
	}
	return (f);
}

size_t				width(const char *s, size_t *i)
{
	size_t		ret;

	ret = ft_atoi(s + *i);
	while (s[*i] && s[*i] >= '0' && s[*i] <= '9')
		++(*i);
	return (ret);
}

size_t				precision(const char *s, size_t *i)
{
	size_t		ret;

	if (s[*i] && s[*i] == '.')
	{
		++(*i);
		ret = ft_atoi(s + *i);
	}
	while (s[*i] && s[*i] >= '0' && s[*i] <= '9')
		++(*i);
	return (ret);
}

unsigned char		specifier(const char *s, size_t *i)
{
	if (contains(SPECIFIERS, s[*i]))
	{
		(*i) += 2;
		return (s[*i]);
	}
	return (0);
}
