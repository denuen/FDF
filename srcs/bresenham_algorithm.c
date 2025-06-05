/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:34:17 by apintaur          #+#    #+#             */
/*   Updated: 2025/02/06 10:02:43 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_bresenham_init(t_bsm *bsm, t_point *p0, t_point *p1, int _case);
static void	ft_bresenham_plot_w(t_mlx *data, t_point m0, t_point p1);
static void	ft_bresenham_plot_h(t_mlx *data, t_point m0, t_point p1);

//Bresenham's algorithm
void	ft_bresenham_plot(t_mlx *data, t_point m0, t_point p1)
{
	if (fabs(p1.x - m0.x) > fabs(p1.y - m0.y))
		ft_bresenham_plot_w(data, m0, p1);
	else
		ft_bresenham_plot_h(data, m0, p1);
}

//Bresenham's algorithm (width case)
static void	ft_bresenham_plot_w(t_mlx *data, t_point m0, t_point p1)
{
	int		i;
	t_point	p0;
	t_bsm	bsm;
	t_cc	color;

	i = 0;
	p0 = m0;
	ft_bresenham_init(&bsm, &p0, &p1, 1);
	if (bsm.dx != 0)
	{
		bsm.p = (2 * (bsm.dy - bsm.dx));
		while (i < bsm.dx + 1)
		{
			color = ft_color_interpolate(p0.color, p1.color, bsm.dy / bsm.dx);
			mymlx_pixel_put(data, p0.x + i, p0.y, color);
			if (bsm.p >= 0)
			{
				p0.y += bsm.dir;
				bsm.p -= (2 * bsm.dx);
			}
			bsm.p += (2 * bsm.dy);
			i++;
		}
	}
}

//Bresenham's algorithm (height case)
static void	ft_bresenham_plot_h(t_mlx *data, t_point m0, t_point p1)
{
	int		i;
	t_point	p0;
	t_bsm	bsm;
	t_cc	color;

	i = 0;
	p0 = m0;
	ft_bresenham_init(&bsm, &p0, &p1, 2);
	if (bsm.dy != 0)
	{
		bsm.p = 2 * bsm.dx - bsm.dy;
		while (i < bsm.dy + 1)
		{
			color = ft_color_interpolate(p0.color, p1.color, bsm.dx / bsm.dy);
			mymlx_pixel_put(data, p0.x, p0.y + i, color);
			if (bsm.p >= 0)
			{
				p0.x += bsm.dir;
				bsm.p -= 2 * bsm.dy;
			}
			bsm.p += 2 * bsm.dx;
			i++;
		}
	}
}

//Bresenham's structure attributes init
static void	ft_bresenham_init(t_bsm *bsm, t_point *p0, t_point *p1, int _case)
{
	t_point	tmp;

	if ((_case == 1 && p0->x > p1->x)
		|| (_case == 2 && p0->y > p1->y))
	{
		tmp = *p0;
		*p0 = *p1;
		*p1 = tmp;
	}
	bsm->dx = p1->x - p0->x;
	bsm->dy = p1->y - p0->y;
	if (_case == 1)
	{
		bsm->dir = 1 - 2 * (bsm->dy < 0);
		bsm->dy *= bsm->dir;
	}
	else
	{
		bsm->dir = 1 - 2 * (bsm->dx < 0);
		bsm->dx *= bsm->dir;
	}
}
