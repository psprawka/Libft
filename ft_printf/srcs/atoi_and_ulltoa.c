/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_and_ulltoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 11:13:42 by psprawka          #+#    #+#             */
/*   Updated: 2017/07/03 15:39:01 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**--------------------- UNSIGNED LONG LONG TO ARRAY ----------------------------
*/

void		ucount(unsigned long long int nb, int *size)
{
	while (nb != 0)
	{
		*size += 1;
		nb /= 10;
	}
}

char		*ft_ulltoa(unsigned long long int nb)
{
	char	*str;
	int		size;

	size = 0;
	ucount(nb, &size);
	str = (char *)malloc(size);
	str[size--] = '\0';
	while (size > -1)
	{
		str[size--] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}
