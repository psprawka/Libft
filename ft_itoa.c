/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:34:42 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/21 19:34:44 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		count(int n, unsigned int *size)
{
	if ((n > 0) || (n < 0))
	{
		*size += 1;
		count(n / 10, size);
	}
	else
		return ;
}

static void		fill_table(int if_neg, int n, char *tab, int size)
{
	tab += size;
	*tab-- = '\0';
	if (n == -2147483648)
	{
		*tab-- = '8';
		size--;
		n = 214748364;
	}
	else
		n = (if_neg == 1 ? n - n - n : n);
	while (size-- > 0)
	{
		if ((if_neg == 1) && (size == 0))
			*tab = '-';
		else
			*tab-- = n % 10 + 48;
		n /= 10;
	}
}

char			*ft_itoa(int n)
{
	unsigned int	size;
	char			*tab;
	int				if_neg;

	if_neg = (n < 0 ? 1 : 0);
	size = (n < 0 ? 1 : 0);
	count(n, &size);
	size = (n == 0 ? 1 : size);
	if (!(tab = (char *)malloc(size + 1)))
		return ((char *)'\0');
	fill_table(if_neg, n, tab, size);
	return (tab);
}
