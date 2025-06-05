/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:33:49 by apintaur          #+#    #+#             */
/*   Updated: 2025/02/06 10:58:20 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mymlx_init_local(t_mlx *data)
{
	t_point	img_center;
	t_point	win_center;

	img_center.x = (data->m.width) / 2.0f;
	img_center.y = (data->m.height) / 2.0f;
	win_center.x = WIDTH / 2.0f;
	win_center.y = HEIGHT / 2.0f;
	data->op.scale = (WIDTH / data->m.width + HEIGHT / data->m.height) / 4.5;
	data->op.translate.x = win_center.x - (img_center.x * data->op.scale);
	data->op.translate.y = win_center.y - (img_center.y * data->op.scale);
	data->op.translate.z = 0;
	data->op.rotate = (t_point){0.0f, 0.0f, 0.0f, 0.0f};
	data->op.height = 0.2f;
	data->op.projection = 1;
}

void	mymlx_init(t_mlx *data, char *filename)
{
	data->mlx_p = NULL;
	data->pic.win.p = NULL;
	data->pic.img.p = NULL;
	data->mlx_p = mlx_init();
	data->pic.win.p = mlx_new_window(data->mlx_p, WIDTH, HEIGHT, "FDF");
	data->pic.img.p = mlx_new_image(data->mlx_p, WIDTH, HEIGHT);
	data->pic.img.addr = mlx_get_data_addr(data->pic.img.p, \
		&data->pic.img.bits_per_pixel, &data->pic.img.lenght, \
		&data->pic.img.endian);
	data->m.point = NULL;
	data->op.keycode = 0;
	data->op.projection = ISOMETRIC;
	data->m.max = (t_mm){0.0f, 0.0f, 0.0f};
	data->m.max = (t_mm){0.0f, 0.0f, 0.0f};
	ft_matrix_create_ff(data, filename);
	mymlx_init_local(data);
	mlx_do_key_autorepeaton(data->mlx_p);
}

int	mymlx_destroy(t_mlx *data)
{
	if (data)
	{
		mlx_destroy_image(data->mlx_p, data->pic.img.p);
		mlx_destroy_window(data->mlx_p, data->pic.win.p);
		mlx_destroy_display(data->mlx_p);
		free(data->mlx_p);
		if (data->m.point)
			free (data->m.point);
		return (1);
	}
	return (-1);
}

int	mymlx_switch_scaleop(t_mlx *data)
{
	if (data->op.keycode == XK_f)
		data->op.height += 0.01;
	else if (data->op.keycode == XK_g)
		data->op.height -= 0.01;
	else if (data->op.keycode == XK_plus || data->op.keycode == XK_equal)
		data->op.scale += 1.2;
	else if (data->op.keycode == XK_minus)
	{
		if (data->op.scale - 1.2 < 1.5)
			data->op.scale = 1.5;
		else
			data->op.scale -= 1.2;
	}
	else
		return (0);
	return (1);
}

int	mymlx_switch_opop(t_mlx *data)
{
	if (data->op.keycode == XK_w && data->op.projection != PARALLEL)
		data->op.rotate.x += 0.1f;
	else if (data->op.keycode == XK_a && data->op.projection != PARALLEL)
		data->op.rotate.y -= 0.1f;
	else if (data->op.keycode == XK_s && data->op.projection != PARALLEL)
		data->op.rotate.x -= 0.1f;
	else if (data->op.keycode == XK_d && data->op.projection != PARALLEL)
		data->op.rotate.y += 0.1f;
	else if (data->op.keycode == XK_j)
		data->op.rotate.z += 0.01f;
	else if (data->op.keycode == XK_k)
		data->op.rotate.z -= 0.01f;
	else if (data->op.keycode == XK_Up)
		data->op.translate.y -= 30;
	else if (data->op.keycode == XK_Down)
		data->op.translate.y += 30;
	else if (data->op.keycode == XK_Left)
		data->op.translate.x -= 30;
	else if (data->op.keycode == XK_Right)
		data->op.translate.x += 30;
	else
		return (0);
	return (1);
}
