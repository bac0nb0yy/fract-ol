/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:15:35 by dtelnov           #+#    #+#             */
/*   Updated: 2022/12/04 02:11:55 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	hdl_keyboard(int keycode, t_data *data, t_movements *moves)
{
	if (keycode == 0x00ffab)
	{
		moves->num_zooms += 1;
		render_image(data, moves);
	}
	else if (keycode == 0x00ffad)
	{
		moves->num_zooms -= 1;
		render_image(data, moves);
	}
	else if (keycode == 0x00ff51)
	{
		moves->num_x -= 1;
		render_image(data, moves);
	}
	else if (keycode == 0x00ff52)
	{
		moves->num_y -= 1;
		render_image(data, moves);
	}
	else if (keycode == 0x00ff53)
	{
		moves->num_x += 1;
		render_image(data, moves);
	}
	else if (keycode == 0x00ff54)
	{
		moves->num_y += 1;
		render_image(data, moves);
	}
	if (keycode == XK_ESCAPE)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_loop_end(data->mlx);
	}
	return (0);
}
