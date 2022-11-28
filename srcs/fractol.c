/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:52:13 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/28 11:35:46 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	ft_close(int keycode, t_vars *vars)
{
	printf("Key pressed : %x\n",keycode);
	if (keycode == XK_ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
		return (1);
	}
	return (0);
}

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	const unsigned int	MAX_ITERATION = 142;
	const unsigned int	OUTPUT_WIDTH = 1080;
	const unsigned int	OUTPUT_HEIGHT = 920;
	const long double	START_X = -0.75;
	const long double	START_Y = 0.0;
	const long double	ZOOM = 1.1;
	unsigned int		x = 0;
	unsigned int		y = 0;

	/*const unsigned int COLOR_TABLE[] = {
    0x00000000, 0x00FFFFFF, 0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FFFF00, 0x0000FFFF, 0x00FF00FF, 0x00C0C0C0, 0x00808080, 
    0x00800000, 0x00808000, 0x00008000, 0x00800080, 0x00008080, 0x00000080
	};*/

	const unsigned int COLOR_TABLE[] = {
    0xf7df, 0xff5a, 0x07ff, 0x7ffa, 0xf7ff, 0xf7bb, 0xff38, 0xff59, 0x001f, 0x895c, 
    0xa145, 0xddd0, 0x5cf4, 0x7fe0, 0xd343, 0xfbea, 0x64bd, 0xffdb, 0xd8a7, 0x07ff, 
    0x0011, 0x0451, 0xbc21, 0xad55, 0x0320, 0xbdad, 0x8811, 0x5345, 0xfc60, 0x9999, 
    0x8800, 0xecaf, 0x8df1, 0x49f1, 0x2a69, 0x067a, 0x901a, 0xf8b2, 0x05ff, 0x6b4d, 
    0x1c9f, 0xd48e, 0xb104, 0xffde, 0x2444, 0xf81f, 0xdefb, 0xffdf, 0xfea0, 0xdd24, 
    0x8410, 0x0400, 0xafe5, 0xf7fe, 0xfb56, 0xcaeb, 0x4810, 0xfffe, 0xf731, 0xe73f, 
    0xff9e, 0x7fe0, 0xffd9, 0xaedc, 0xf410, 0xe7ff, 0xffda, 0xd69a, 0x9772, 0xfdb8, 
    0xfd0f, 0x2595, 0x867f, 0x839f, 0x7453, 0xb63b, 0xfffc, 0x07e0, 0x3666, 0xff9c, 
    0xf81f, 0x8000, 0x6675, 0x0019, 0xbaba, 0x939b, 0x3d8e, 0x7b5d, 0x07d3, 0x4e99, 
    0xc0b0, 0x18ce, 0xf7ff, 0xff3c, 0xff36, 0xfef5, 0x0010, 0xffbc, 0x8400, 0x6c64, 
    0xfd20, 0xfa20, 0xdb9a, 0xef55, 0x9fd3, 0xaf7d, 0xdb92, 0xff7a, 0xfed7, 0xcc27, 
    0xfe19, 0xdd1b, 0xb71c, 0x8010, 0xf800, 0xbc71, 0x435c, 0x8a22, 0xfc0e, 0xf52c, 
    0x2c4a, 0xffbd, 0xa285, 0xc618, 0x867d, 0x6ad9, 0x7412, 0xffdf, 0x07ef, 0x4416, 
    0xd5b1, 0x0410, 0xddfb, 0xfb08, 0x471a, 0xec1d, 0xd112, 0xf6f6, 0xffff, 0xf7be, 
    0xffe0, 0x9e66, 0x0000
	};

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, OUTPUT_WIDTH, OUTPUT_HEIGHT, "Implementer un fractale");
	img.img = mlx_new_image(vars.mlx, OUTPUT_WIDTH, OUTPUT_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (y < OUTPUT_HEIGHT)
	{
		x = 0;
		long double p_i = 1.5 * (y - OUTPUT_HEIGHT / 2.0) / (0.5 * ZOOM * OUTPUT_HEIGHT) + START_Y;
		while (x < OUTPUT_WIDTH)
		{
			long double p_r = 1.5 * (x - OUTPUT_WIDTH / 2.0) / (0.5 * ZOOM * OUTPUT_WIDTH) + START_X;
			long double new_r = 0, new_i = 0, old_r = 0, old_i = 0;
			unsigned int i = 0;
			while ((new_r * new_r + new_i * new_i) < 4.0 && i < MAX_ITERATION) {
                old_r = new_r;
                old_i = new_i;
                new_r = old_r * old_r - old_i * old_i + p_r;
                new_i = 2.0 * old_r * old_i + p_i;
                ++i;
            }
			unsigned int color = COLOR_TABLE[i];
			my_mlx_pixel_put(&img, x, y, color);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	if (mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars) == 1)
		return(0);
	mlx_loop(vars.mlx);
	return (0);
}