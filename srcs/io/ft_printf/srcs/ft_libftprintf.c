/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:28:15 by psprawka          #+#    #+#             */
/*   Updated: 2017/12/28 18:28:18 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** ------------------------- LIBFTPRINTF FUNCTIONS -----------------------------
*/

void	ftt_putchar(char c, t_flags *bag)
{
	write(1, &c, 1);
	bag->ret += 1;
}

void	ftt_putstr(char const *s, t_flags *bag)
{
	int	i;

	i = 0;
	while (s[i])
		ftt_putchar(s[i++], bag);
}

void	ftt_putnbr(long int nb, t_flags *bag)
{
	if (nb == LL_MIN)
	{
		ftt_putstr("-9223372036854775808", bag);
		return ;
	}
	if (nb < 0)
	{
		ftt_putchar('-', bag);
		nb = -nb;
	}
	if (nb < 10)
	{
		ftt_putchar(nb + 48, bag);
		return ;
	}
	ftt_putnbr(nb / 10, bag);
	ftt_putchar(nb % 10 + 48, bag);
	return ;
}

int		if_unicode(t_flags *bag, wchar_t *ws)
{
	if (ARGUMENT != 7)
	{
		if (ws == NULL)
			ftt_putstr("(null)", bag);
		else
			while (*ws != '\0')
				write(1, ws++, 1);
		return (-1);
	}
	return (0);
}
