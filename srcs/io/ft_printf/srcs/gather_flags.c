/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:39:39 by psprawka          #+#    #+#             */
/*   Updated: 2017/11/27 11:39:41 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	flags(char *f, int *i, t_flags *bag)
{
	while (f[*i] != '\0' && (f[*i] == '+' || f[*i] == '-' ||
			f[*i] == '0' || f[*i] == ' ' || f[*i] == '#'))
	{
		if (f[*i] == '+')
		{
			PLUS = true;
			SPACE = false;
		}
		if (f[*i] == '-')
		{
			MINUS = true;
			ZERO = false;
		}
		if (f[*i] == '#')
			HASH = true;
		if (f[*i] == '0' && MINUS == false)
			ZERO = true;
		if (f[*i] == ' ' && PLUS == false)
			SPACE = true;
		*i += 1;
	}
}

void	width(char *f, int *i, t_flags *bag, va_list ap)
{
	char	*ptr;

	ptr = f;
	while (f[*i] != '\0' && (f[*i] == '*' || (f[*i] > 47 && f[*i] < 58)))
	{
		if (f[*i] == '*')
		{
			WIDTH = va_arg(ap, int);
			*i += 1;
		}
		else
		{
			ptr += *i;
			WIDTH = ft_atoi(ptr);
			while (f[*i] > 47 && f[*i] < 58)
				*i += 1;
		}
	}
}

void	precision(char *f, int *i, t_flags *bag, va_list ap)
{
	char	*ptr;

	ptr = f;
	PRECISION = 0;
	if (f[*i] != '.')
		return ;
	*i += 1;
	IF_PREC = true;
	while (f[*i] != '\0' && (f[*i] == '-' || f[*i] == '*' ||
			(f[*i] > 47 && f[*i] < 58)))
	{
		if (f[*i] == '*')
		{
			STAR = true;
			PRECISION = va_arg(ap, int);
			*i += 1;
		}
		else
		{
			ptr += *i;
			PRECISION = ft_atoi(ptr);
			while ((f[*i] != '\0' && f[*i] > 47 && f[*i] < 58) || f[*i] == '-')
				*i += 1;
		}
	}
}

/*
** bag->argument may egual:
** - 1 if h appears;
** - 2 if hh appears;
** - 3 if l appears;
** - 4 if ll appears;
** - 5 if j appears;
** - 6 if z appears;
*/

void	arguments(char *f, int *i, t_flags *bag)
{
	while (f[*i] != '\0' && (f[*i] == 'h' || f[*i] == 'l' || f[*i] == 'z' ||
			f[*i] == 'j' || f[*i] == 'q'))
	{
		if (f[*i] == 'h' && ARGUMENT == 1)
			ARGUMENT = 2;
		else if (f[*i] == 'h' && ARGUMENT != 6 && ARGUMENT != 5)
			ARGUMENT = 1;
		else if (f[*i] == 'l' && ARGUMENT == 3)
			ARGUMENT = 4;
		else if (f[*i] == 'l')
			ARGUMENT = 3;
		else if (f[*i] == 'j')
			ARGUMENT = 5;
		else if (f[*i] == 'z')
			ARGUMENT = 6;
		else if (f[*i] == 'q')
			ARGUMENT = 7;
		*i += 1;
	}
}

void	type(char t, t_flags *bag)
{
	if (t == 'd' || t == 's' || t == 'S' || t == 'p' || t == 'D' ||
		t == 'i' || t == 'o' || t == 'O' || t == 'u' || t == 'X' ||
		t == 'U' || t == 'x' || t == 'c' || t == 'C' || t == 'E' ||
		t == 'e' || t == 'f' || t == 'F' || t == '%' || t == 'b')
		TYPE = t;
	else
		TYPE = -1;
}
