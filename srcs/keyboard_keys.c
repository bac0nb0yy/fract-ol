/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 02:43:24 by dtelnov           #+#    #+#             */
/*   Updated: 2022/12/05 01:35:54 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	hdl_zoom_in(t_all *all)
{
	all->num_zooms += 1;
	render_image(all);
}

void	hdl_zoom_out(t_all *all)
{
	all->num_zooms -= 1;
	render_image(all);
}

void	hdl_escape(t_all *all)
{
	clear_all(all);
	mlx_loop_end(all->mlx);
}
