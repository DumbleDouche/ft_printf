/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:41:04 by rchoquer          #+#    #+#             */
/*   Updated: 2017/07/11 23:36:18 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>
# include <stdlib.h>

# define MALLOC(s, n)		malloc(s * n)
# define SPECIFIERS			"sSpdDioOuUxXcC%"
# define INTS				"dDioOuUxX"
# define STRS				"sScC"
# define SPECIAL			"%p"
# define FLOATS				""
# define HEXU				"0123456789ABCDEF"
# define HEXL				"0123456789abcdef"
# define _U					unsigned
# define _C					char
# define _S					short
# define _I					int
# define _L					long
# define _LL				long long
# define _M					intmax_t
# define _UM				uintmax_t
# define _UC				_U _C
# define _US				_U _S
# define _UI				_U _I
# define _UL				_U _L
# define _ULL				_U _LL
# define FLA				args.list[i].flags
# define WID				args.list[i].width
# define PRE				args.list[i].precision
# define LEN				args.list[i].length
# define SPE				args.list[i].specifier
# define TL(c)				ft_tolower(c)

typedef struct				s_arg
{
	size_t			index;
	size_t			width;
	ssize_t			precision;
	char			flags;
	char			length;
	char			specifier;
}							t_arg;

typedef struct				s_args
{
	t_arg			*list;
	size_t			printed;
	size_t			len;
}							t_args;

int							ft_printf(const char *format, ...);
void						ft_putnbr_r(uintmax_t n, size_t base, char l);
int8_t						contains(const char *s, char c);
size_t						core(va_list l, t_args args, size_t i);
size_t						int_types(va_list l, t_args args, size_t i);
size_t						i_shorts(va_list l, t_args args, size_t i);
size_t						i_ints(va_list l, t_args args, size_t i);
size_t						i_longs(va_list l, t_args args, size_t i);
size_t						i_intmax(va_list l, t_args args, size_t i);
size_t						digits(long nbr, unsigned int base);
size_t						get_base(char c);
size_t						string_types(va_list l, t_args args, size_t i);
size_t						special_types(va_list l, t_args args, size_t i);
size_t						ft_putchar(char c);
size_t						ft_wputchar(char c, size_t width, char fla);
size_t						ft_nputchar(char c, size_t n);
size_t						ft_putstr(const _C *s, size_t w, ssize_t p, _C f);
size_t						ft_putnstr(const char *string, size_t size);
size_t						ft_putnbr(intmax_t nb, char c, size_t w, _C f);
size_t						ft_putnbr_u(uintmax_t nb, char c, size_t w, _C f);
size_t						count_args(const char *s);
size_t						arg_size(const char *s);
size_t						width(const char *s, size_t *i);
ssize_t						precision(const char *s, size_t *i);
size_t						loc_conv(const char *s);
size_t						ft_strlen(const char *s);
t_args						setup_args(size_t n);
t_args						format_string_parser(const char *s);
char						type(t_args args, size_t index);
char						flag(const char *s, size_t *i);
char						length(const char *s, size_t *i);
char						specifier(const char *s, size_t *i);
long long					ft_atoi(const char *str);
unsigned char				ft_tolower(unsigned char c);
static inline void			setup_arg(t_arg *arg);

#endif
