/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:09:14 by dmorar            #+#    #+#             */
/*   Updated: 2019/02/14 14:12:37 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	newdata(t_olst *fdf)
{
	fdf->zm = WID * 0.55 / (fdf->hig - 1);
	if (fdf->hig < fdf->wit)
		fdf->zm = WID * 0.55 / (fdf->wit - 1);
	fdf->cx = (WID / 2) - (fdf->wit * fdf->zm / 2);
	fdf->cy = (WID / 2) - (fdf->hig * fdf->zm / 2);
	fdf->my = fdf->hig / 2;
	fdf->mx = fdf->wit / 2;
}

void	datahorizont(t_olst *fdf, int i, int j)
{
	fdf->x1 = fdf->point[i][j].x * fdf->zm + fdf->cx;
	fdf->y1 = fdf->point[i][j].y * fdf->zm + fdf->cy;
	fdf->x2 = fdf->point[i + 1][j].x * fdf->zm + fdf->cx;
	fdf->y2 = fdf->point[i + 1][j].y * fdf->zm + fdf->cy;
	fdf->colx1 = fdf->point[i][j].color;
	bresenham(fdf);
}

void	datavertic(t_olst *fdf, int i, int j)
{
	fdf->x1 = fdf->point[i][j].x * fdf->zm + fdf->cx;
	fdf->y1 = fdf->point[i][j].y * fdf->zm + fdf->cy;
	fdf->x2 = fdf->point[i][j + 1].x * fdf->zm + fdf->cx;
	fdf->y2 = fdf->point[i][j + 1].y * fdf->zm + fdf->cy;
	fdf->coly1 = fdf->point[i][j].color;
	bresenham(fdf);
}
