/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:07:52 by dmorar            #+#    #+#             */
/*   Updated: 2019/02/14 14:49:37 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# define WID 1300

typedef struct	s_ilst
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_ilst;
typedef struct	s_olst
{
	t_ilst		**point;
	int			hig;
	int			wit;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			bpp;
	int			line_size;
	int			endian;
	int			cx;
	int			cy;
	int			zm;
	float		x;
	float		z;
	float		y;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			colx1;
	int			coly1;
	int			my;
	int			mx;
	char		**str;
}				t_olst;
int				main(int argc, char **argv);
void			justdraw(t_olst *fdf);
void			newdata(t_olst *fdf);
int				ft_atoi_base(const char *str, int str_base);
int				key_release(int key, t_olst *fdf);
void			rotation(t_olst *fdf, int i, int j, int key);
void			iso(t_olst *fdf);
int				colorit(char *wrd);
int				ft_atoi_base(const char *str, int str_base);
int				mouse_release(int button, int x, int y, t_olst *fdf);
void			openwindow(t_olst *fdf);
int				readandmalloc(int fd);
void			strtoi(t_olst *fdf);
void			datahorizont(t_olst *fdf, int i, int j);
void			datavertic(t_olst *fdf, int i, int j);
void			newdata(t_olst *fdf);
void			drawagain(t_olst *fdf);
int				mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(),
				void *param);
void			iteration(int key, t_olst *fdf);
int				closemap(void *fdf);
void			bresenham(t_olst *fdf);
void			horizontal(t_olst *fdf);
void			vertical(t_olst *fdf);
void			swapint(t_olst *fdf);
void			checkvalid(char *str);
char			**readmap(int fd);
int				base(int c, int base);
#endif
