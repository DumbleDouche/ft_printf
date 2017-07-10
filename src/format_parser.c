/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 22:36:51 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/10 20:41:22 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int8_t			contains(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		++i;
	}
	return (0);
}

size_t			loc_conv(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] && s[i] != '%')
		++i;
	return (i);
}

size_t			arg_size(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && (s[i] == '-' || s[i] == '+' || s[i] == ' ' || s[i] == '#'
	|| s[i] == '0'))
		++i;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		++i;
	if (s[i] == '.')
	{
		++i;
		while (s[i] && (s[i] >= '0' && s[i] <= '9'))
			++i;
	}
	if (contains(SPECIFIERS, s[i]))
		++i;
	return (i);
}

size_t			count_args(const char *s)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			++count;
			i += arg_size(s + i + 1) + 1;
		}
		else
			++i;
	}
	return (count);
}

t_args			format_string_parser(const char *s)
{
	size_t		i;
	size_t		count;
	t_args		args;

	i = 0;
	count = 0;
	args = setup_args(count_args(s));
	while (s[i])
	{
		if (s[i] == '%')
		{
			++i;
			args.list[count].flags = flag(s, &i);
			args.list[count].width = width(s, &i);
			args.list[count].precision = precision(s, &i);
			args.list[count].length = length(s, &i);
			args.list[count].specifier = specifier(s, &i);
			// printf("this is the result: |%c| index: |%zu|\n", args.list[count].specifier, count);
			++count;
		}
		else
			++i;
	}
	return (args);
}
