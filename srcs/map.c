/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:35:23 by apintaur          #+#    #+#             */
/*   Updated: 2025/03/25 00:45:04 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_map_plot_h(t_mlx *data);
static void	ft_map_plot_w(t_mlx *data);
void		ft_map_restore_extrema(t_mlx *data);

int	ft_map_plot(t_mlx *data)
{
	ft_check_valid_matrix(data, __func__);
	ft_map_restore_extrema(data);
	ft_map_plot_h(data);
	ft_map_plot_w(data);
	ft_color_map(data);
	return (0);
}

static void	ft_map_plot_h(t_mlx *data)
{
	int		x;
	int		y;
	t_point	p0;
	t_point	p1;

	x = 0;
	while (x < data->m.width)
	{
		y = 1;
		while (y < data->m.height)
		{
			p0 = ft_point_get(data, x, y - 1);
			p1 = ft_point_get(data, x, y);
			ft_std_isometric(data, &p0, &p1);
			ft_bresenham_plot(data, p0, p1);
			y++;
		}
		x++;
	}
}

static void	ft_map_plot_w(t_mlx *data)
{
	int		x;
	int		y;
	t_point	p0;
	t_point	p1;

	x = 1;
	while (x < data->m.width)
	{
		y = 0;
		while (y < data->m.height)
		{
			p0 = ft_point_get(data, x - 1, y);
			p1 = ft_point_get(data, x, y);
			ft_std_isometric(data, &p0, &p1);
			ft_bresenham_plot(data, p0, p1);
			y++;
		}
		x++;
	}
}

void	ft_map_restore_extrema(t_mlx *data)
{
	data->m.max.z = -99999999999.99999f;
	data->m.min.z = 99999999999.99999f;
	ft_matrix_extrema_z(data);
}
