/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:16:13 by dtelnov           #+#    #+#             */
/*   Updated: 2022/12/03 19:29:47 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_close_mouse(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

/*int	hdl_mouse(int button, int x, int y, t_data *data)
{
	(void)data;
	printf("x -> %d\ny -> %d\n", x, y);
	printf("Button pressed : %.4x", button);
	return (0);
}*/
