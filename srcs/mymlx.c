/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:35:37 by apintaur          #+#    #+#             */
/*   Updated: 2025/02/06 10:02:43 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mymlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*tmp_addr;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		tmp_addr = data->pic.img.addr + (y * data->pic.img.lenght \
			+ x * (data->pic.img.bits_per_pixel / 8));
		*((unsigned int *)tmp_addr) = color;
	}
}

int	mymlx_switch_keycode(int keycode, t_mlx *data)
{
	if (keycode == XK_Escape)
		exit(mymlx_destroy(data));
	if (keycode == XK_i)
	{
		mymlx_init_local(data);
		data->op.projection = ISOMETRIC;
	}
	data->op.keycode = keycode;
	return (1);
}

int	mymlx_render(t_mlx *data)
{
	ft_bzero(data->pic.img.addr, WIDTH * HEIGHT * \
		(data->pic.img.bits_per_pixel / 8));
	ft_map_plot(data);
	mlx_put_image_to_window(data->mlx_p, data->pic.win.p, \
		data->pic.img.p, 0, 0);
	return (0);
}

int	mymlx_exit(t_mlx *data)
{
	exit (mymlx_destroy(data));
}
