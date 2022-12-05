/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:16:13 by dtelnov           #+#    #+#             */
/*   Updated: 2022/12/05 01:57:35 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_close_mouse(t_all *all)
{
	clear_all(all);
	mlx_loop_end(all->mlx);
	return (0);
}

int	hdl_mouse(int button, int x, int y, t_all *all)
{
	printf("x ->%d, y -> %d\n", x, y);
	if (button == 4)
		hdl_zoom_in(all);
	else if (button == 5)
		hdl_zoom_out(all);
	(void)all;
	return (0);
}

/*int	hdl_mouse(int button, int x, int y, t_data *data)
{
	(void)data;
	printf("x -> %d\ny -> %d\n", x, y);
	printf("Button pressed : %.4x", button);
	return (0);
}*/
