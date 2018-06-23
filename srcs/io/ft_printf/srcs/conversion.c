/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 22:18:18 by psprawka          #+#    #+#             */
/*   Updated: 2017/11/27 22:18:20 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*convert_ws(wchar_t *str, int len)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(len + 1);
	while (i < len)
	{
		new[i] = (char)str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*convert_binary(unsigned long int nb)
{
	char	*print;
	int		i;

	i = 0;
	print = ft_memalloc(33);
	if (nb == 0)
		print[i] = '0';
	while (nb != 0)
	{
		print[i++] = (nb % 2) + 48;
		nb /= 2;
	}
	return (ft_strrev(print));
}
