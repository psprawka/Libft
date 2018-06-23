/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:52:52 by psprawka          #+#    #+#             */
/*   Updated: 2017/11/28 17:52:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_format(char x)
{
	write(1, &x, 1);
}

void	print(int start, int end, char *format)
{
	while (start < end && format[start] != '\0')
		print_format(format[start++]);
}

void	print_plus(t_flags *bag, long int *nb)
{
	if (PLUS == true && *nb > -1)
		ftt_putchar('+', bag);
	if (*nb < 0 && *nb != (LL_MIN))
	{
		ftt_putchar('-', bag);
		*nb *= -1;
	}
	PLUS = false;
}

void	print_hash(t_flags *bag, unsigned long long int nb)
{
	if ((TYPE == 'x' || TYPE == 'X') && HASH == true && nb != 0)
		(TYPE == 'x') ? ftt_putstr("0x", bag) : ftt_putstr("0X", bag);
	if ((TYPE == 'o' || TYPE == 'O') && HASH == true && PRECISION - LEN < 0)
		ftt_putstr("0", bag);
	if (TYPE == 'p' && HASH == true)
		ftt_putstr("0x", bag);
	HASH = false;
}

void	print_perc(t_flags *bag)
{
	int	width;

	width = 0;
	while (MINUS == false && width++ < WIDTH - 1)
		ZERO == true ? ftt_putchar('0', bag) : ftt_putchar(' ', bag);
	if (bag->type != -1)
		ftt_putchar('%', bag);
	while (width++ < WIDTH - 1)
		ZERO == true ? ftt_putchar('0', bag) : ftt_putchar(' ', bag);
}
