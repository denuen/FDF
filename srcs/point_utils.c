/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:35:50 by apintaur          #+#    #+#             */
/*   Updated: 2025/03/25 01:09:20 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	ft_point_get(t_mlx *data, int x, int y)
{
	if (!ft_point_isvalid(data, x, y))
		return ((t_point){0.0f, 0.0f, 0.0f, 0.0f});
	return (data->m.point[y * data->m.width \
			+ x]);
}

float	ft_point_dotscal(t_point p0, t_point p1)
{
	return (p0.x * p1.x + p0.y * p1.y + p0.z * p1.z);
}

static t_point	ft_point_normalize(t_point normal)
{
	float	len;

	len = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
	if (len > 0.0001f)
	{
		normal.x /= len;
		normal.y /= len;
		normal.z /= len;
	}
	else
	{
		normal.x = 0.0f;
		normal.y = 0.0f;
		normal.z = 1.0f;
	}
	return (normal);
}

t_point	ft_point_getznorm(t_mlx *data, float x, float y)
{
	float	dzdx;
	float	dzdy;
	t_point	normal;

	if (x <= 0 || x >= data->m.width - 1 || y <= 0 || y >= data->m.height - 1)
		return ((t_point){0.0f, 0.0f, 1.0f, 0x0});
	dzdx = (ft_point_get(data, x + 1, y).z - \
	ft_point_get(data, x - 1, y).z) / 2.0f;
	dzdy = (ft_point_get(data, x, y + 1).z - \
	ft_point_get(data, x, y - 1).z) / 2.0f;
	normal.x = -dzdx;
	normal.y = -dzdy;
	normal.z = 1.0f;
	normal.color = 0x0;
	return (ft_point_normalize(normal));
}

int	ft_point_isvalid(t_mlx *data, int x, int y)
{
	if (x < 0 || x >= data->m.width || y < 0 || y >= data->m.height)
		return (0);
	if ((y * data->m.width + x) >= (data->m.width * data->m.height))
		return (0);
	return (1);
}
