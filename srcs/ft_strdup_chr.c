/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_newline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:08:19 by psprawka          #+#    #+#             */
/*   Updated: 2017/10/02 15:08:22 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup_chr(char *src, char c)
{
	char	*copy;
	int		i;

	i = 0;
	while (src[i] != '\0' && src[i] != c)
		i++;
	copy = (char*)malloc(i + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
