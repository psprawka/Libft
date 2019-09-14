/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:35:14 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/14 13:25:18 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Ft_putchar_fd() writes a charater to specified fd.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
