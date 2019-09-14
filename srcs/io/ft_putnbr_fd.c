/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:35:37 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/14 20:15:59 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_putnbr_fd(long long nb, int fd)
{
	nb = 0; fd = 0;
	// if (nb == -2147483648)
	// {
	// 	ft_putstr_fd("-2147483648", fd);
	// 	return ;
	// }
	// if (nb < 0)
	// {
	// 	ft_putchar_fd('-', fd);
	// 	nb = -nb;
	// }
	// if (nb < 10)
	// {
	// 	ft_putchar_fd(nb + 48, fd);
	// 	return ;
	// }
	// ft_putnbr_fd(nb / 10, fd);
	// ft_putchar_fd(nb % 10 + 48, fd);
	// return ;
}
