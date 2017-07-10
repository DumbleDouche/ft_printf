/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:41:04 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/10 22:29:53 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/////

#include <stdio.h>

/////


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define MALLOC(size, count)	malloc(size * count)

# define SPECIFIERS				"sSpdDioOuUxXcC%"
# define INTS					"diouXx"
# define FLOATS					""
# define HEXU					"0123456789ABCDEF"

 typedef struct					s_arg
 {
	size_t			index;
	size_t			width;
	size_t			precision;
	unsigned char	flags;
	unsigned char	length;
	unsigned char	specifier;
 }								t_arg;
 
 typedef struct					s_args
 {
 	t_arg 			*list;
	size_t			printed;
 	size_t			len;
 }								t_args;
 
 int							ft_printf(const char *format, ...);
 int							core(va_list alist, t_args args, size_t index);
 char							type(t_args args, size_t index);
 size_t							ft_putnstr(const char *string, size_t size);
 size_t							ft_putnbr(int nb, size_t base);
 void							ft_putnbr_r(unsigned long, size_t base);
 void							ft_putchar(char c);
 size_t							count_args(const char *s);
 size_t							arg_size(const char *s);
 int8_t							contains(const char *s, char c);
 size_t							width(const char *s, size_t *i);
 size_t							precision(const char *s, size_t *i);
 size_t							loc_conv(const char *s);
 size_t							digits(long nbr, unsigned int base);
 long long						ft_atoi(const char *str);
 t_args							setup_args(size_t n);
 t_args							format_string_parser(const char *s);
 unsigned char					flag(const char *s, size_t *i);
 unsigned char					length(const char *s, size_t *i);
 unsigned char					specifier(const char *s, size_t *i);
 static inline void				setup_arg(t_arg *arg);

#endif
