/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:39:57 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 14:29:07 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
# include <wchar.h>
# include "libft.h"

# define LL_MAX 	9223372036854775807
# define LL_MIN 	-9223372036854775807 - 1

/*
** all colors defined below:
*/

# define NORMAL		"\x1B[0m"
# define BLACK		"\x1B[30m"
# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGNETA	"\x1B[35m"
# define CYAN		"\x1B[36m"
# define WHITE		"\x1B[37m"

/*
** width may equal -1 when * appears;
** precision may egual -1 when * appears;
**
** argument is the very last flag and may egual:
**		1 if h appears;
**		2 if hh appears;
**		3 if l appears;
**		4 if ll appears;
**		5 if j appears;
**		6 if z appears;
**		7 if q appears;		<-- bonus part, prints unicode in case of C and S
*/

/*
** defines for struct s_flags in order to preserve the readability of src code:
*/

# define PLUS		bag->plus
# define MINUS		bag->minus
# define ZERO		bag->zero
# define SPACE		bag->space
# define HASH		bag->hash
# define IF_PREC	bag->ifprec
# define STAR		bag->star
# define DISPLAY	bag->display
# define TYPE		bag->type
# define WIDTH		bag->width
# define PRECISION	bag->precision
# define ARGUMENT	bag->argument
# define LEN		bag->len

typedef struct		s_flags
{
	bool	plus;
	bool	minus;
	bool	zero;
	bool	space;
	bool	hash;
	bool	ifprec;
	bool	display;
	bool	star;
	char	type;
	int		width;
	int		precision;
	int		argument;
	int		ret;
	int		len;
}					t_flags;

/*
** libft functions:
*/

int					ft_printf(const char *format, ...);

/*
** printf functions:
*/

void				ftt_putnbr(long int nb, t_flags *bag);
void				ftt_putchar(char c, t_flags *bag);
void				ftt_putstr(char const *s, t_flags *bag);

void				print_perc(t_flags *bag);
void				print_plus(t_flags *bag, long int *nb);
void				print(int start, int end, char *format);
void				print_hash(t_flags *bag, unsigned long long int nb);

void				print_int(t_flags *bag, va_list ap);
void				print_char(t_flags *bag, va_list ap);
void				print_float(t_flags *bag, va_list ap);
void				print_wchar(t_flags *bag, va_list ap);
void				print_string(t_flags *bag, va_list ap);
void				print_pointer(t_flags *bag, va_list ap);
void				print_wchar_str(t_flags *bag, va_list ap);
void				print_unsigned_int(t_flags *bag, va_list ap);

void				flags(char *f, int *i, t_flags *bag);
void				width(char *f, int *i, t_flags *bag, va_list ap);
void				precision(char *f, int *i, t_flags *bag, va_list ap);
void				arguments(char *f, int *i, t_flags *bag);
void				type(char type, t_flags *bag);

char				*convert_ws(wchar_t *str, int len);
char				*convert(t_flags *bag, long long int nb);
char				*convert_binary(unsigned long int nb);

char				*ft_ulltoa(unsigned long long int nb);
int					colors(char *s, t_flags *bag);
int					if_unicode(t_flags *bag, wchar_t *ws);
#endif
