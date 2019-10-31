/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:03:28 by dmorar            #+#    #+#             */
/*   Updated: 2019/02/11 15:48:33 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	strtoi(t_olst *fdf)
{
	char	**wrd;
	int		x;
	int		y;

	y = 0;
	fdf->point = (t_ilst **)malloc(sizeof(t_ilst) * fdf->hig);
	while (fdf->str[y] != '\0')
	{
		x = 0;
		wrd = ft_strsplit(fdf->str[y], ' ');
		while (wrd[fdf->wit] != '\0')
			fdf->wit++;
		fdf->point[y] = (t_ilst *)malloc(sizeof(t_ilst) * fdf->wit);
		while (wrd[x] != '\0')
		{
			fdf->point[y][x].x = x;
			fdf->point[y][x].y = y;
			fdf->point[y][x].z = ft_atoi(wrd[x]);
			fdf->point[y][x].color = colorit(wrd[x]);
			free(wrd[x]);
			x++;
		}
		free(wrd);
		y++;
	}
}

void	checkvalid(char *str)
{
	int i;
	int m;
	int n;

	i = 0;
	m = 0;
	n = 0;
	while (str[i] != '\0')
	{
		n = 0;
		while (str[i] != '\n' && str[i] != '\0')
		{
			if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\n' ||
			str[i + 1] == '\0'))
				n++;
			i++;
		}
		if (m == 0)
			m = n;
		if (m != n)
			exit(0);
		if (str[i] == '\n')
			i++;
	}
}

char	**readmap(int fd)
{
	char	buf[10001];
	char	*tmp;
	int		k;
	char	*arr;
	char	**str;

	arr = ft_strnew(0);
	while ((k = read(fd, buf, 10000)) > 0)
	{
		buf[k] = '\0';
		tmp = arr;
		arr = ft_strjoin(arr, buf);
		free(tmp);
	}
	if (arr[0] == '\0')
		exit(0);
	checkvalid(arr);
	str = ft_strsplit(arr, '\n');
	free(arr);
	return (str);
}

int		readandmalloc(int fd)
{
	t_olst	*fdf;

	fdf = (t_olst *)malloc(sizeof(t_olst));
	fdf->hig = 0;
	fdf->wit = 0;
	fdf->str = readmap(fd);
	while (fdf->str[fdf->hig] != '\0')
		fdf->hig++;
	strtoi(fdf);
	newdata(fdf);
	openwindow(fdf);
	return (0);
}
