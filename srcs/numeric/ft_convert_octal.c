/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:36:46 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 13:18:01 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_octal(unsigned long int nb)
{
	char	print[22];
	int		i;

	i = 0;
	ft_bzero(print, 22);
	if (nb == 0)
		i++;
	while (nb != 0)
	{
		print[i++] = (nb % 8) + 48;
		nb /= 8;
	}
	print[i] = '\0';
	return (ft_strrev(print));
}
