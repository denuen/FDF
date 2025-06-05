/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_lighting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:43:05 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/05 19:53:51 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colors.h"
#include "../includes/fdf.h"

int	ft_color_get_gradient(t_gradient grad[5], float pos)
{
	int		i;
	float	t;
	float	smoothed_t;

	i = -1;
	if (pos <= grad[0].position)
		return (grad[0].color);
	if (pos >= grad[4].position)
		return (grad[4].color);
	while (++i < 4)
	{
		if (pos >= grad[i].position && pos <= grad[i + 1].position)
		{
			t = (pos - grad[i].position) / \
					(grad[i + 1].position - grad[i].position);
			smoothed_t = t * t * (3.0f - 2.0f * t);
			return (ft_color_interpolate(grad[i].color, \
						grad[i + 1].color, smoothed_t));
		}
	}
	return (grad[4].color);
}

static float	ft_calculate_diffuse(t_point normal, t_point light_dir)
{
	float	diffuse;

	diffuse = fmaxf(ft_point_dotscal(normal, light_dir), 0.0f);
	return (powf(diffuse, 0.8f));
}

int	ft_color_getlight(int color, float height, \
						t_point normal, t_point light_dir)
{
	t_color		c;
	float		intensity;
	float		diffuse;
	float		ambient;

	diffuse = ft_calculate_diffuse(normal, light_dir);
	ambient = LIGHT_DEFLINE * 1.5f;
	if (ambient > 0.4f)
		ambient = 0.4f;
	intensity = ambient + diffuse * (1.0f - ambient) +\
				(height * LIGHT_INTENSITY * 0.7f);
	intensity = powf(intensity, 0.9f);
	intensity = fminf(intensity, 1.2f);
	c.r = fminf((int)(((color >> 16) & 0xFF) * intensity), 255);
	c.g = fminf((int)(((color >> 8) & 0xFF) * intensity), 255);
	c.b = fminf((int)((color & 0xFF) * intensity), 255);
	return (((color & 0xFF000000) | (c.r << 16) | (c.g << 8) | c.b));
}
