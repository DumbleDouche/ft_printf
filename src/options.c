/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 04:25:20 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 07:25:52 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char				flag(const char *s, size_t *i)
{
	char	f;

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

char				length(const char *s, size_t *i)
{
	char	f;

	f = 0;
	if (s[*i] == 'h')
	{
		++(*i);
		f = 0b00000001;
		if (s[*i] == 'h' && ++(*i))
			f = 0b10000001;
	}
	else if (s[*i] == 'l')
	{
		++(*i);
		f = 0b00000010;
		if (s[*i] == 'l' && ++(*i))
			f = 0b10000010;
	}
	else if (s[*i] == 'j' && ++(*i))
		f = 0b00000100;
	else if (s[*i] == 'z' && ++(*i))
		f = 0b00001000;
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

char				specifier(const char *s, size_t *i)
{
	if (contains(SPECIFIERS, s[*i]))
	{
		(*i) += 2;
		return (s[*i - 2]);
	}
	return (0);
}
