/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:19:33 by dmorar            #+#    #+#             */
/*   Updated: 2019/02/13 16:49:08 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdlib.h>

int		mouse_release(int button, int x, int y, t_olst *fdf)
{
	(void)x;
	(void)y;
	if (button == 5)
		fdf->zm += 5;
	if (button == 4)
		if (fdf->zm - 5 > 0)
			fdf->zm = fdf->zm - 5;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_bzero(fdf->img_data, WID * WID * 4);
	justdraw(fdf);
	return (0);
}

int		closemap(void *fdf)
{
	(void)fdf;
	exit(0);
	return (0);
}

void	openwindow(t_olst *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WID, WID, "mlx 42");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WID, WID);
	fdf->img_data = (int*)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
	&fdf->line_size, &fdf->endian);
	justdraw(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, key_release, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, closemap, fdf);
	mlx_mouse_hook(fdf->win_ptr, mouse_release, fdf);
	mlx_loop(fdf->mlx_ptr);
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (argc == 1 || argc > 2)
	{
		if (argc == 1)
			ft_putstr("ERROR! Add file.");
		if (argc > 2)
			ft_putstr("ERROR! Add only one file.");
		return (0);
	}
	readandmalloc(fd);
	return (0);
}
