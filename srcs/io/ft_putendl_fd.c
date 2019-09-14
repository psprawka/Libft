/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:55:59 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/14 13:28:52 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Ft_putendl_fd() writes a string to specified fd followed by a newline.
*/
void	ft_putendl_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
	ft_putchar_fd('\n', fd);
}
