/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:27:24 by psprawka          #+#    #+#             */
/*   Updated: 2017/09/19 15:27:26 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *str, char to_find)
{
	int len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	while (len > 0)
	{
		if (*str == to_find)
			return (str);
		str--;
		len--;
	}
	if (*str == to_find)
		return (str);
	return (0);
}
