/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:35:37 by apintaur          #+#    #+#             */
/*   Updated: 2025/02/06 10:58:40 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//Mlx management functions utility [mymlx_utils.c]
int	mymlx_switch_scaleop(t_mlx *data);
int	mymlx_switch_opop(t_mlx *data);

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
	else if (keycode == XK_p)
	{
		mymlx_init_local(data);
		data->op.projection = PARALLEL;
	}
	else if (keycode == XK_b)
	{
		mymlx_init_local(data);
		data->op.rotate = (t_point){-M_PI / 4, M_PI + \
		(7.0f * (M_PI / 180.0f)), 0.0f, 0.0f};
		data->op.translate.x += 800;
	}
	data->op.keycode = keycode;
	return (1);
}

int	mymlx_render(t_mlx *data)
{
	if (mymlx_switch_opop(data) || mymlx_switch_scaleop(data))
		data->op.keycode = 0;
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
