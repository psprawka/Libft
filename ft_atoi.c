/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 11:13:42 by psprawka          #+#    #+#             */
/*   Updated: 2017/07/03 15:39:01 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	change(char *str, char *num, int len)
{
	int		i;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\t')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == '\v'))
		i++;
	if (((str[i] == '-') || (str[i] == '+'))
		&& (str[i + 1] > 47) && (str[i + 1] < 58))
	{
		num[0] = str[i];
		len++;
		i++;
	}
	while ((str[i] > 47) && (str[i] < 58))
	{
		num[len] = str[i];
		len++;
		i++;
	}
	return (len);
}

int			ft_atoi(char *str)
{
	long long	nb;
	int			i;
	char		num[40];
	int			len;

	nb = 0;
	len = 0;
	len = change(str, num, len) - 1;
	i = 1;
	while ((len > -1) && (num[len] != '-') && (num[len] != '+'))
	{
		nb = nb + (num[len] - 48) * i;
		i *= 10;
		len--;
	}
	if (num[0] == '-')
		nb = nb - nb - nb;
	if (nb > 9223372036854775807 || nb < -9223372036854775807)
		return (0);
	return (nb);
}
