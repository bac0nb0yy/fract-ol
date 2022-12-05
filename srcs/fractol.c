/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:51:24 by dtelnov           #+#    #+#             */
/*   Updated: 2022/12/05 01:42:21 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	clear_all(t_all *all)
{
	mlx_destroy_image(all->mlx, all->img);
	mlx_destroy_window(all->mlx, all->win);
}

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->addr + (y * all->ll + x * (all->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	calcul_mandelbrot(t_coordinates *m)
{
	unsigned int	i;

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

void	render_image(t_all *all)
{
	t_coordinates	m;
	unsigned int	color;

	all->r_zoom = (0.5 * (ZOOM * pow(ZOOM_FACTOR, all->num_zooms)));
	all->r_x = START_X + (MOVE_FACTOR * all->num_x);
	all->r_y = START_Y + (MOVE_FACTOR * all->num_y);
	m.y = 0;
	while (m.y < HEIGHT)
	{
		m.x = 0;
		m.p_i = 1.5 * (m.y - HEIGHT / 2.0) / (all->r_zoom * HEIGHT)
			+ all->r_y;
		while (m.x < WIDTH)
		{
			m.p_r = 1.5 * (m.x - WIDTH / 2.0) / (all->r_zoom * WIDTH)
				+ all->r_x;
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
	t_all		all;

	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, WIDTH, HEIGHT, "Fract-ol");
	all.img = mlx_new_image(all.mlx, WIDTH, HEIGHT);
	all.addr = mlx_get_data_addr(all.img, &all.bpp, &all.ll, &all.endian);
	all.num_zooms = 0;
	all.num_x = 0;
	all.num_y = 0;
	render_image(&all);
	mlx_mouse_hook(all.win, hdl_mouse, &all);
	mlx_key_hook(all.win, hdl_keyboard, &all);
	mlx_hook(all.win, 17, 0, ft_close_mouse, &all);
	mlx_loop(all.mlx);
	mlx_destroy_display(all.mlx);
	free(all.mlx);
	return (0);
}
