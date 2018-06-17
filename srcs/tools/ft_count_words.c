/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:27:56 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 14:18:23 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_words(char *str)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'))
			i++;
		if (str[i])
			words += 1;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\v')
			i++;
	}
	return (words);
}