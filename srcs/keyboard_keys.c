/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 02:43:24 by dtelnov           #+#    #+#             */
/*   Updated: 2022/12/04 03:06:09 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	hdl_zoom_in(t_data *data, t_movements *moves)
{
	moves->num_zooms += 1;
	render_image(data, moves);
}

void	hdl_zoom_out(t_data *data, t_movements *moves)
{
	printf("lol");
	moves->num_zooms -= 1;
	render_image(data, moves);
}

void	hdl_escape(t_data *data, t_movements *moves)
{
	(void)moves;
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
}
