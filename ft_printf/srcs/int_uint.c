/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:19:42 by psprawka          #+#    #+#             */
/*   Updated: 2017/11/27 14:19:44 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** print_width_int prints both precision and width
*/

#define T			(TYPE == 'i' || TYPE == 'd')
#define ARG			(va_arg(ap, void*))

#define RETURN_H 	T ? (short int)ARG : (unsigned short int)ARG
#define RETURN_HH	T ? (char)ARG : (unsigned char)ARG
#define RETURN_L	(T || TYPE == 'D') ? (long int)ARG : (unsigned long int)ARG
#define RETURN_LL	T ? (long long int)ARG : (unsigned long long int)ARG
#define RETURN_J	T ? (intmax_t)ARG : (uintmax_t)ARG
#define RETURN_Z	(size_t)va_arg(ap, size_t)

long long int	assign_value(t_flags *bag, va_list ap)
{
	if (TYPE != 'i' && TYPE != 'd' && TYPE != 'o' && TYPE != 'u' && TYPE != 'x'
		&& TYPE != 'X')
		ARGUMENT = 0;
	if (ARGUMENT == 1)
		return (RETURN_H);
	if (ARGUMENT == 2)
		return (RETURN_HH);
	if (ARGUMENT == 3 || TYPE == 'D')
		return (RETURN_L);
	if (ARGUMENT == 4)
		return (RETURN_LL);
	if (ARGUMENT == 5)
		return (RETURN_J);
	if (ARGUMENT == 6)
		return (RETURN_Z);
	if (TYPE == 'd' || TYPE == 'i')
		return ((int)va_arg(ap, void*));
	if (TYPE == 'U' || TYPE == 'O')
		return ((unsigned long long int)va_arg(ap, void*));
	if (TYPE == 'u' || TYPE == 'o' || TYPE == 'X' || TYPE == 'x')
		return ((unsigned int)va_arg(ap, void*));
	return ((long long int)NULL);
}

/*
** ----------------------------- INT - i, d, D ---------------------------------
*/

void			parse_int(t_flags *bag, long int nb)
{
	char	*len;

	len = ft_itoa(nb);
	LEN = (nb == 0 && IF_PREC == true ? 0 : ft_strlen(len));
	free(len);
	nb < 0 ? LEN-- : LEN;
	MINUS = WIDTH < 0 || (PRECISION < 0 && STAR == false) ? true : MINUS;
	WIDTH = WIDTH < 0 ? WIDTH * -1 : WIDTH;
	PRECISION = PRECISION < 0 && STAR == false ? PRECISION * -1 : PRECISION;
	PRECISION -= LEN;
	WIDTH -= PRECISION > 0 ? PRECISION + LEN : LEN;
	PLUS == true || nb < 0 ? WIDTH-- : WIDTH;
	ZERO = (IF_PREC == true) && STAR == false ? false : ZERO;
	WIDTH = SPACE == true && WIDTH < 1 && nb > 0 ? 1 : WIDTH;
	SPACE = nb < 0 ? false : SPACE;
}

void			print_int(t_flags *bag, va_list ap)
{
	long int nb;

	nb = assign_value(bag, ap);
	parse_int(bag, nb);
	if (ZERO == true)
		print_plus(bag, &nb);
	if (SPACE == true && WIDTH--)
		ftt_putchar(' ', bag);
	while (MINUS == false && WIDTH-- > 0)
		ZERO == true ? ftt_putchar('0', bag) : ftt_putchar(' ', bag);
	print_plus(bag, &nb);
	while (PRECISION-- > 0)
		ftt_putchar('0', bag);
	if ((LEN > 0) || (nb == 0 && IF_PREC == false))
		ftt_putnbr(nb, bag);
	while (WIDTH-- > 0)
		ftt_putchar(' ', bag);
}

/*
** -------------------- UNSIGNED INT - o, O, u, U, x, X ------------------------
*/

void			parse_unsigned_int(t_flags *bag)
{
	DISPLAY = IF_PREC == true && PRECISION == 0 && ((HASH == false) ||
			(HASH == true && (TYPE == 'x' || TYPE == 'X'))) ? false : true;
	WIDTH -= (TYPE == 'x' || TYPE == 'X') && HASH == true ? 2 : 0;
	WIDTH -= (TYPE == 'o' || TYPE == 'O') && HASH == true ? 1 : 0;
	MINUS = PRECISION < 0 ? true : MINUS;
	WIDTH = (PRECISION < 0) ? PRECISION * -1 : WIDTH;
	PRECISION -= LEN;
	WIDTH -= PRECISION > 0 ? PRECISION + LEN : LEN;
	PLUS == true ? WIDTH-- : WIDTH;
	ZERO = IF_PREC == true || SPACE == true ? false : ZERO;
}

void			print_unsigned_int(t_flags *bag, va_list ap)
{
	unsigned long long int	nb;
	char					*print;

	nb = assign_value(bag, ap);
	print = (nb > LL_MAX && (TYPE == 'u' || TYPE == 'U')) ?
		ft_ulltoa(nb) : convert(bag, nb);
	LEN = nb == 0 ? 0 : ft_strlen(print);
	parse_unsigned_int(bag);
	if (ZERO == true)
		print_hash(bag, nb);
	if (MINUS == false)
		while (WIDTH-- > 0)
			ZERO == true ? ftt_putchar('0', bag) : ftt_putchar(' ', bag);
	print_hash(bag, nb);
	while (PRECISION-- > 0)
		ftt_putchar('0', bag);
	if (DISPLAY == true)
		ftt_putstr(print, bag);
	while (WIDTH-- > 0)
		ftt_putchar(' ', bag);
	free(print);
}
