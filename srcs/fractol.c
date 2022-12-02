/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:51:24 by dtelnov           #+#    #+#             */
/*   Updated: 2022/12/02 03:21:23 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *all, int x, int y, int color)
{
	char	*dst;

	dst = all->addr + (y * all->ll + x * (all->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned short	calcul_mandelbrot(t_coordinates *m)
{
	unsigned short	i;

	i = 0;
	m->n_r = 0;
	m->n_i = 0;
	m->old_r = 0;
	m->old_i = 0;
	while (m->n_r * m->n_r + m->n_i * m->n_i < 4.0 && i < MAX_ITERATION)
	{
		m->old_r = m->n_r;
		m->old_i = m->n_i;
		m->n_r = m->old_r * m->old_r - m->old_i * m->old_i + m->p_r;
		m->n_i = 2.0 * m->old_r * m->old_i + m->p_i;
		++i;
	}
	return (get_color(i));
}

void	render_image(t_data *all, unsigned int *num_zooms)
{
	t_coordinates	m;
	unsigned short	color;
	float			real_zoom;

	real_zoom = (0.5 * (ZOOM * pow((double)ZOOM_FACTOR, (double)*num_zooms)));
	m.y = 0;
	while (m.y < HEIGHT)
	{
		m.x = 0;
		m.p_i = 1.5 * (m.y - HEIGHT / 2.0) / (real_zoom * HEIGHT) + START_Y;
		while (m.x < WIDTH)
		{
			m.p_r = 1.5 * (m.x - WIDTH / 2.0) / (real_zoom * ZOOM * WIDTH) + START_X;
			color = calcul_mandelbrot(&m);
			my_mlx_pixel_put(all, m.x, m.y, color);
			++m.x;
		}
		++m.y;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
}

int	main(void)
{
	t_data			all;
	unsigned int	num_zooms;

	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, WIDTH, HEIGHT, "Fract-ol");
	all.img = mlx_new_image(all.mlx, WIDTH, HEIGHT);
	all.addr = mlx_get_data_addr(all.img, &all.bpp, &all.ll, &all.endian);
	num_zooms = 0;
	render_image(&all, &num_zooms);
	mlx_hook(all.win, 2, 1 << 0, hdl_keyboard, &all);
	mlx_hook(all.win, 17, 0, ft_close_mouse, &all);
	mlx_loop(all.mlx);
	mlx_destroy_display(all.mlx);
	free(all.mlx);
	return (EXIT_SUCCESS);
}
