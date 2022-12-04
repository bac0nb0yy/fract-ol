/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:15:35 by dtelnov           #+#    #+#             */
/*   Updated: 2022/12/04 03:15:49 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	index_keycode_function(int *keycodes, int keycode, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (keycode == keycodes[i])
			return (i);
		++i;
	}
	return (-1);
}

int	hdl_keyboard(int keycode, t_data *data, t_movements *moves)
{
	static int	keycodes[] = {ESCAPE, ZOOM_IN, ZOOM_OUT, L_ARROW, T_ARROW,
		R_ARROW, B_ARROW};
	static void	(*f[])(t_data *, t_movements *) = {hdl_escape, hdl_zoom_in,
		hdl_zoom_out, hdl_left_arrow, hdl_top_arrow, hdl_right_arrow,
		hdl_bottom_arrow};
	const int	size_keycodes = sizeof(keycodes) / sizeof(keycodes[0]);	
	int			index;

	index = index_keycode_function(keycodes, keycode, size_keycodes);
	printf("key pressed : %d and index : %d\n", keycode, index);
	if (index != -1)
		f[index](data, moves);
	return (0);
}
