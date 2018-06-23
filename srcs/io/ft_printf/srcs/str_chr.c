/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:34:05 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/22 14:34:17 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** print_width prints both precision and width for either characher or string
*/

void	printf_parse(t_flags *bag)
{
	ZERO = PRECISION < 0 ? false : ZERO;
	LEN = (PRECISION < LEN && IF_PREC == true) ? PRECISION : LEN;
	WIDTH = WIDTH < 0 && TYPE == 'c' ? WIDTH * -1 : WIDTH;
	WIDTH = (PRECISION < 0) ? PRECISION * -1 : WIDTH - LEN;
	WIDTH = (TYPE == 'c' && PRECISION < 0) ? (PRECISION * -1) - 1 : WIDTH;
	MINUS = (TYPE == 'c' && PRECISION < 0) ? true : MINUS;
	if (IF_PREC == true && PRECISION == 0 && TYPE == 'c')
		WIDTH--;
}

/*
** ----------------------- STRING - s | WSTRING - S ----------------------------
*/

void	print_string(t_flags *bag, va_list ap)
{
	char	*str;

	if (ARGUMENT == 3)
	{
		print_wchar_str(bag, ap);
		return ;
	}
	str = va_arg(ap, char *);
	str = (str == NULL ? "(null)" : str);
	if (colors(str, bag) == 1)
		return ;
	LEN = ft_strlen(str);
	printf_parse(bag);
	while (MINUS == false && WIDTH-- > 0)
		ZERO == true ? ftt_putchar('0', bag) : ftt_putchar(' ', bag);
	while (LEN-- > 0 && *str != '\0')
		ftt_putchar(*str++, bag);
	while (WIDTH-- > 0)
		ftt_putchar(' ', bag);
}

void	print_wchar_str(t_flags *bag, va_list ap)
{
	char	*s;
	wchar_t	*ws;

	ws = (wchar_t *)va_arg(ap, wchar_t *);
	if (if_unicode(bag, ws) == -1)
		return ;
	s = *ws == '\0' ? "\0" : ft_convert_uni(*ws++);
	if (ws != NULL && ft_wstrlen(ws) == -1 && ARGUMENT != 7)
	{
		free(s);
		return ;
	}
	while (ws != NULL && *ws != '\0' && ARGUMENT == 7)
		s = ft_strjoin(s, ft_convert_uni(*ws++), 1);
	LEN = s == NULL ? 0 : ft_strlen(s);
	printf_parse(bag);
	while (MINUS == false && WIDTH-- > 0)
		ZERO == true ? ftt_putchar('0', bag) : ftt_putchar(' ', bag);
	while (LEN-- > 0 && *s != '\0')
		ftt_putchar(*s++, bag);
	while (WIDTH-- > 0)
		ftt_putchar(' ', bag);
}

/*
** ----------------------------- CHAR - c, C -----------------------------------
*/

void	print_char(t_flags *bag, va_list ap)
{
	unsigned char x;

	x = (unsigned char)va_arg(ap, int);
	LEN = 1;
	printf_parse(bag);
	while (MINUS == false && WIDTH-- > 0)
		ZERO == true ? ftt_putchar('0', bag) : ftt_putchar(' ', bag);
	ftt_putchar(x, bag);
	while (WIDTH-- > 0)
		ftt_putchar(' ', bag);
}

void	print_wchar(t_flags *bag, va_list ap)
{
	char	*x;
	wchar_t	wx;

	wx = va_arg(ap, wint_t);
	x = ft_convert_uni((wchar_t)(wx));
	LEN = 1;
	printf_parse(bag);
	while (MINUS == false && WIDTH-- > 0)
		ZERO == true ? ftt_putchar('0', bag) : ftt_putchar(' ', bag);
	ftt_putstr(x, bag);
	while (WIDTH-- > 0)
		ftt_putchar(' ', bag);
	free(x);
}
