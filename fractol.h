/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:53:06 by dtelnov           #+#    #+#             */
/*   Updated: 2022/12/05 01:32:36 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>

# define ESCAPE 0xff1b
# define ZOOM_IN 0xffab
# define ZOOM_OUT 0xffad
# define L_ARROW 0xff51
# define T_ARROW 0xff52
# define R_ARROW 0xff53
# define B_ARROW 0xff54
# define MAX_ITERATION 141
# define WIDTH 1080
# define HEIGHT 920
# define START_X -0.75
# define START_Y 0.0
# define MOVE_FACTOR 0.1
# define ZOOM 1.1
# define ZOOM_FACTOR 1.1

typedef struct s_all {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	double	num_zooms;
	double	num_x;
	double	num_y;
	double	r_zoom;
	double	r_x;
	double	r_y;
}				t_all;

typedef struct s_coordinates {
	double			p_i;
	double			p_r;
	double			n_r;
	double			n_i;
	double			old_r;
	double			old_i;
	unsigned short	x;
	unsigned short	y;
}				t_coordinates;

void			my_mlx_pixel_put(t_all *all, int x, int y, int color);
unsigned int	calcul_mandelbrot(t_coordinates *m);
void			render_image(t_all *all);
int				get_color(int i);
int				hdl_keyboard(int keycode, t_all *all);
int				ft_close_mouse(t_all *all);
int				hdl_mouse(int button, int x, int y, t_all *all);
void			hdl_escape(t_all *all);
void			hdl_zoom_out(t_all *all);
void			hdl_zoom_in(t_all *all);
void			hdl_left_arrow(t_all *all);
void			hdl_top_arrow(t_all *all);
void			hdl_right_arrow(t_all *all);
void			hdl_bottom_arrow(t_all *all);
void			clear_all(t_all *all);

#endif
