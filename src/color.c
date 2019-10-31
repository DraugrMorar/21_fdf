/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:57:32 by dmorar            #+#    #+#             */
/*   Updated: 2019/02/13 16:47:07 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		base(int c, int base)
{
	char	*str;
	char	*str2;
	int		i;

	str = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int	nb;
	int negatif;
	int i;

	nb = 0;
	negatif = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == ' ' || str[i] == '\n'
	|| str[i] == 't' || str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negatif = 1;
		i++;
	}
	while (base(str[i], str_base) != -1)
	{
		nb = nb * str_base;
		nb = nb + base(str[i], str_base);
		i++;
	}
	if (negatif)
		return (-nb);
	return (nb);
}

int		colorit(char *wrd)
{
	int	i;
	int color;

	if (ft_strchr(wrd, ',') == NULL)
		return (0xFFFFFF);
	i = 0;
	while (wrd[i] != 'x')
		i++;
	i++;
	color = ft_atoi_base(&wrd[i], 16);
	return (color);
}
