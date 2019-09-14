/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:28:15 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/14 23:06:52 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** ------------------------- LIBFTPRINTF FUNCTIONS -----------------------------
*/

void	ftp_putchar(char c, t_flags *bag)
{
	write(1, &c, 1);
	bag->ret += 1;
}

void	ftp_putstr(char const *s, t_flags *bag)
{
	int	i;

	i = 0;
	while (s[i])
		ftp_putchar(s[i++], bag);
}

void	ftp_putnbr(long int nb, t_flags *bag)
{
	if (nb == LL_MIN)
	{
		ftp_putstr("-9223372036854775808", bag);
		return ;
	}
	if (nb < 0)
	{
		ftp_putchar('-', bag);
		nb = -nb;
	}
	if (nb < 10)
	{
		ftp_putchar(nb + 48, bag);
		return ;
	}
	ftp_putnbr(nb / 10, bag);
	ftp_putchar(nb % 10 + 48, bag);
}


char	*ftp_itoa_dynamic_alloc(int nbr)
{
	int			sign;
	int			count;
	char		*str;

	count = 1;
	sign = nbr;
	while (sign /= 10)
		count++;
	sign = nbr < 0 ? 1 : 0;
	count = nbr < 0 ? count += 1 : count;
	str = (char *)malloc(count + 1);
	str[count] = '\0';
	if (nbr == -2147483648)
		return ("-2147483648");
	if (sign == 1)
		str[0] = '-';
	nbr = nbr < 0 ? nbr *= -1 : nbr;
	while (--count >= sign)
	{
		str[count] = nbr >= 10 ? (nbr % 10) + 48 : nbr + 48;
		nbr /= 10;
	}
	return (str);
}

int		ftp_if_unicode(t_flags *bag, wchar_t *ws)
{
	if (ARGUMENT != 7)
	{
		if (ws == NULL)
			ftp_putstr("(null)", bag);
		else
			while (*ws != '\0')
				write(1, ws++, 1);
		return (-1);
	}
	return (0);
}
