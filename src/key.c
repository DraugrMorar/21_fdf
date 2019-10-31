/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:03:22 by dmorar            #+#    #+#             */
/*   Updated: 2019/02/13 16:35:30 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	iso(t_olst *fdf)
{
	int previous_x;
	int previous_y;
	int i;
	int j;

	i = 0;
	while (i < fdf->hig)
	{
		j = 0;
		while (j < fdf->wit)
		{
			previous_x = fdf->point[i][j].x;
			previous_y = fdf->point[i][j].y;
			fdf->point[i][j].x = (previous_x - previous_y) * cos(0.523599)
			+ fdf->mx;
			fdf->point[i][j].y = -(fdf->point[i][j].z) +
			(previous_x + previous_y) * sin(0.523599) + fdf->my;
			j++;
		}
		i++;
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_bzero(fdf->img_data, WID * WID * 4);
	justdraw(fdf);
}

void	rotation(t_olst *fdf, int i, int j, int key)
{
	float r;

	r = 0.174533;
	fdf->x = fdf->point[i][j].x - fdf->mx;
	fdf->y = fdf->point[i][j].y - fdf->my;
	fdf->z = fdf->point[i][j].z;
	if (key == 125 || key == 123 || key == 65)
		r = -0.174533;
	if (key == 126 || key == 125)
	{
		fdf->point[i][j].y = fdf->my + fdf->y * cos(r) - fdf->z * sin(r);
		fdf->point[i][j].z = fdf->y * sin(r) + fdf->z * cos(r);
	}
	if (key == 124 || key == 123)
	{
		fdf->point[i][j].x = fdf->mx + fdf->x * cos(r) + fdf->z * sin(r);
		fdf->point[i][j].z = -fdf->x * sin(r) + fdf->z * cos(r);
	}
	if (key == 82 || key == 65)
	{
		fdf->point[i][j].x = fdf->mx + fdf->x * cos(r) - fdf->y * sin(r);
		fdf->point[i][j].y = fdf->my + fdf->x * sin(r) + fdf->y * cos(r);
	}
}

void	iteration(int key, t_olst *fdf)
{
	int i;
	int j;

	i = -1;
	while (++i < fdf->hig)
	{
		j = -1;
		while (++j < fdf->wit)
		{
			if (key == 1)
				fdf->point[i][j].y += 1;
			if (key == 13)
				fdf->point[i][j].y -= 1;
			if (key == 2)
				fdf->point[i][j].x += 1;
			if (key == 0)
				fdf->point[i][j].x -= 1;
			rotation(fdf, i, j, key);
		}
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_bzero(fdf->img_data, WID * WID * 4);
	justdraw(fdf);
}

int		key_release(int key, t_olst *fdf)
{
	if (key == 126 || key == 124 || key == 82 || key == 125 ||
	key == 123 || key == 65 || key == 1 || key == 13 || key == 2
	|| key == 0 || key == 69)
		iteration(key, fdf);
	if (key == 29)
		drawagain(fdf);
	if (key == 49)
		iso(fdf);
	if (key == 53)
		exit(0);
	return (0);
}

void	drawagain(t_olst *fdf)
{
	int i;

	i = 0;
	while (i < fdf->hig)
	{
		free(fdf->point[i]);
		i++;
	}
	free(fdf->point);
	strtoi(fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_bzero(fdf->img_data, WID * WID * 4);
	justdraw(fdf);
}
