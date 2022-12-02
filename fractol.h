/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:53:06 by dtelnov           #+#    #+#             */
/*   Updated: 2022/12/02 03:59:18 by dtelnov          ###   ########.fr       */
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

# define XK_ESCAPE 0xff1b
# define MAX_ITERATION 141
# define WIDTH 1080
# define HEIGHT 920
# define START_X -0.75
# define START_Y 0.0
# define ZOOM 1.1
# define ZOOM_FACTOR 1.1

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_data;

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

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int	calcul_mandelbrot(t_coordinates *m);
void			render_image(t_data *all, unsigned int *num_zooms);
int				get_color(int i);
int				hdl_keyboard(int keycode, t_data *data, unsigned int *num_zooms);
int				ft_close_mouse(t_data *data);

#endif
