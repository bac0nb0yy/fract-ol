/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:15:35 by dtelnov           #+#    #+#             */
/*   Updated: 2022/12/02 03:20:40 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	hdl_keyboard(int keycode, t_data *data, unsigned int *num_zooms)
{
	if (keycode == XK_ESCAPE)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_loop_end(data->mlx);
		return (0);
	}
	else if (keycode == 0x00ffab)
	{
		*num_zooms += 1;
		render_image(data, num_zooms);
	}
	return (0);
}
