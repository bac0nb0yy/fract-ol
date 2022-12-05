/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_arrows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 02:28:08 by dtelnov           #+#    #+#             */
/*   Updated: 2022/12/05 01:35:11 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	hdl_left_arrow(t_all *all)
{
	all->num_x -= 1;
	render_image(all);
}

void	hdl_top_arrow(t_all *all)
{
	all->num_y -= 1;
	render_image(all);
}

void	hdl_right_arrow(t_all *all)
{
	all->num_x += 1;
	render_image(all);
}

void	hdl_bottom_arrow(t_all *all)
{
	all->num_y += 1;
	render_image(all);
}
