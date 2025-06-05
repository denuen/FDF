/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:34:45 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/05 18:39:54 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colors.h"
#include "../includes/fdf.h"

static float	ft_get_height_percentage(t_mlx *data, float z_val);
static t_point	ft_rotate_light(t_mlx *data);
int				ft_color_get_gradient(t_gradient grad[5], float pos);
int				ft_color_getlight(int color, float height, t_point normal, \
								t_point light_dir);

// Colors management functions utility [colors_utility.c]
unsigned int	ft_lerp(int start, int end, float t);
void			ft_palette_init(t_gradient palette[6]);
void			ft_normalize_z(float norm_threshold, float *z);

static void	ft_process_point_color(t_mlx *data, t_mm p, t_gradient *palette, \
								t_point rotated_light)
{
	float	z_val;
	float	height_percent;

	z_val = data->m.point[p.y * data->m.width + p.x].z;
	height_percent = ft_get_height_percentage(data, z_val);
	if (height_percent < NORM_THRESHOLD)
		height_percent = powf(height_percent / NORM_THRESHOLD, \
	0.7f) * NORM_THRESHOLD;
	else
		ft_normalize_z(NORM_THRESHOLD, &height_percent);
	p.z = height_percent;
	data->m.point[p.y * data->m.width + p.x].color = ft_color_getlight(\
				ft_color_get_gradient(palette, height_percent), p.z, \
				ft_point_getznorm(data, p.x, p.y), rotated_light);
}

void	ft_color_map(t_mlx *data)
{
	t_mm		p;
	t_gradient	palette[6];
	t_point		rotated_light;

	ft_palette_init(palette);
	rotated_light = ft_rotate_light(data);
	p.y = -1;
	while (++p.y < data->m.height)
	{
		p.x = -1;
		while (++p.x < data->m.width)
			ft_process_point_color(data, p, palette, rotated_light);
	}
}

static float	ft_get_height_percentage(t_mlx *data, float z_val)
{
	float	max_abs_z;
	float	height_percent;
	float	abs_z_val;

	abs_z_val = fabsf(z_val);
	max_abs_z = fmaxf(data->m.max.z, fabsf(data->m.min.z));
	if (max_abs_z <= 0.001f)
		max_abs_z = 0.001f;
	height_percent = abs_z_val / max_abs_z;
	height_percent = powf(height_percent, 0.8f);
	return (fminf(height_percent, 1.0f));
}

static t_point	ft_rotate_light(t_mlx *data)
{
	t_point	rotated_light;
	float	light_len;

	rotated_light = (t_point){0.0f, 0.0f, 1.0f, 0.0f};
	ft_point_rotate_x(&rotated_light, \
					data->op.rotate.x + (35 * (M_PI / 180.0f)));
	ft_point_rotate_y(&rotated_light, \
					data->op.rotate.y + (-15 * (M_PI / 180.0f)));
	ft_point_rotate_z(&rotated_light, data->op.rotate.z);
	light_len = sqrtf(rotated_light.x * rotated_light.x + \
					rotated_light.y * rotated_light.y + \
					rotated_light.z * rotated_light.z);
	rotated_light.x /= light_len;
	rotated_light.y /= light_len;
	rotated_light.z /= light_len;
	return (rotated_light);
}

t_cc	ft_color_interpolate(t_cc c1, t_cc c2, float t)
{
	t_cc	tt;
	t_cc	r;
	t_cc	g;
	t_cc	b;

	tt = ft_lerp((c1 >> 24) & 0xFF, (c2 >> 24) & 0xFF, t);
	r = ft_lerp((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, t);
	g = ft_lerp((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, t);
	b = ft_lerp(c1 & 0xFF, c2 & 0xFF, t);
	return ((tt << 24 | r << 16 | g << 8 | b));
}
