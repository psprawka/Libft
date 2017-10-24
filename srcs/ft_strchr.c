/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:27:37 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/19 15:27:38 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *str, char to_find)
{
	while (*str && *str != to_find)
		str++;
	if (*str == to_find)
		return (str);
	else
		return ((char *)'\0');
}
