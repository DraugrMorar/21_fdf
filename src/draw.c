/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:29:07 by dmorar            #+#    #+#             */
/*   Updated: 2019/02/14 14:18:01 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	horizontal(t_olst *fdf)
{
	int dy;
	int yi;
	int	d;
	int dx;

	dy = fdf->y2 - fdf->y1;
	dx = fdf->x2 - fdf->x1;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	while (fdf->x1++ != fdf->x2)
	{
		if (fdf->x1 >= 0 && fdf->y1 >= 0 && fdf->y1 < WID && fdf->x1 < WID)
			fdf->img_data[fdf->x1 + fdf->y1 * WID] = fdf->colx1;
		if (d > 0)
		{
			fdf->y1 = fdf->y1 + yi;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
	}
}

void	vertical(t_olst *fdf)
{
	int		dx;
	int		xi;
	int		dy;
	int		d;

	dx = fdf->x2 - fdf->x1;
	dy = fdf->y2 - fdf->y1;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	while (fdf->y1++ != fdf->y2)
	{
		if (fdf->x1 >= 0 && fdf->y1 >= 0 && fdf->y1 < WID && fdf->x1 < WID)
			fdf->img_data[fdf->x1 + fdf->y1 * WID] = fdf->colx1;
		if (d > 0)
		{
			fdf->x1 = fdf->x1 + xi;
			d = d - 2 * dy;
		}
		d = d + 2 * dx;
	}
}

void	swapint(t_olst *fdf)
{
	int		buf;

	buf = fdf->x1;
	fdf->x1 = fdf->x2;
	fdf->x2 = buf;
	buf = fdf->y1;
	fdf->y1 = fdf->y2;
	fdf->y2 = buf;
}

void	bresenham(t_olst *fdf)
{
	if (abs(fdf->y2 - fdf->y1) < abs(fdf->x2 - fdf->x1))
	{
		if (fdf->x1 > fdf->x2)
		{
			swapint(fdf);
			horizontal(fdf);
		}
		else
			horizontal(fdf);
	}
	else
	{
		if (fdf->y1 > fdf->y2)
		{
			swapint(fdf);
			vertical(fdf);
		}
		else
			vertical(fdf);
	}
}

void	justdraw(t_olst *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->hig)
	{
		j = 0;
		while (j < fdf->wit)
		{
			if (i < fdf->hig - 1)
				datahorizont(fdf, i, j);
			if (j < fdf->wit - 1)
				datavertic(fdf, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}
