/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_arrows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 02:28:08 by dtelnov           #+#    #+#             */
/*   Updated: 2022/12/04 03:16:10 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	hdl_left_arrow(t_data *data, t_movements *moves)
{
	moves->num_x -= 1;
	render_image(data, moves);
}

void	hdl_top_arrow(t_data *data, t_movements *moves)
{
	moves->num_y -= 1;
	render_image(data, moves);
}

void	hdl_right_arrow(t_data *data, t_movements *moves)
{
	moves->num_x += 1;
	render_image(data, moves);
}

void	hdl_bottom_arrow(t_data *data, t_movements *moves)
{
	moves->num_y += 1;
	render_image(data, moves);
}
