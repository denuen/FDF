/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_projection_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:20:28 by apintaur          #+#    #+#             */
/*   Updated: 2025/02/06 10:02:43 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_std_isometric(t_mlx *data, t_point *p0, t_point *p1)
{
	ft_point_scale(p0, data->op.height, data->op.scale);
	ft_point_scale(p1, data->op.height, data->op.scale);
	ft_point_rotate_x(p0, data->op.rotate.x + (35 * (M_PI / 180.0f)));
	ft_point_rotate_x(p1, data->op.rotate.x + (35 * (M_PI / 180.0f)));
	ft_point_rotate_y(p0, data->op.rotate.y + (-15 * (M_PI / 180.0f)));
	ft_point_rotate_y(p1, data->op.rotate.y + (-15 * (M_PI / 180.0f)));
	ft_point_rotate_z(p0, data->op.rotate.z);
	ft_point_rotate_z(p1, data->op.rotate.z);
	ft_point_translate(p0, data->op.translate);
	ft_point_translate(p1, data->op.translate);
}

void	ft_std_parallel(t_mlx *data, t_point *p0, t_point *p1)
{
	ft_point_scale(p0, data->op.height, data->op.scale);
	ft_point_scale(p1, data->op.height, data->op.scale);
	if (data->op.keycode == XK_d)
		data->op.rotate = (t_point){0.0f, 90.0f, 0.0f, 0.0f};
	else if (data->op.keycode == XK_a)
		data->op.rotate = (t_point){0.0f, -90.0f, 0.0f, 0.0f};
	else if (data->op.keycode == XK_w)
		data->op.rotate = (t_point){90.0f, 0.0f, 0.0f, 0.0f};
	else if (data->op.keycode == XK_s)
		data->op.rotate = (t_point){-90.0f, 0.0f, 0.0f, 0.0f};
	ft_point_rotate_x(p0, data->op.rotate.x * (M_PI / 180.0f));
	ft_point_rotate_x(p1, data->op.rotate.x * (M_PI / 180.0f));
	ft_point_rotate_y(p0, data->op.rotate.y * (M_PI / 180.0f));
	ft_point_rotate_y(p1, data->op.rotate.y * (M_PI / 180.0f));
	ft_point_rotate_z(p0, data->op.rotate.z * (M_PI / 180.0f));
	ft_point_rotate_z(p1, data->op.rotate.z * (M_PI / 180.0f));
	ft_point_translate(p0, data->op.translate);
	ft_point_translate(p1, data->op.translate);
}
