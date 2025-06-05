/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:35:43 by apintaur          #+#    #+#             */
/*   Updated: 2025/02/06 10:02:43 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_point_rotate_x(t_point *p, float angle)
{
	t_point	old;

	old = *p;
	p->y = old.y * cos(angle) - old.z * sin(angle);
	p->z = old.y * sin(angle) + old.z * cos(angle);
}

void	ft_point_rotate_y(t_point *p, float angle)
{
	t_point	old;

	old = *p;
	p->x = old.x * cos(angle) + old.z * sin(angle);
	p->z = -old.x * sin(angle) + old.z * cos(angle);
}

void	ft_point_rotate_z(t_point *p, float angle)
{
	t_point	old;

	old = *p;
	p->x = old.x * cos(angle) - old.y * sin(angle);
	p->y = old.x * sin(angle) + old.y * cos(angle);
}

void	ft_point_translate(t_point *p, t_point factor)
{
	p->x += factor.x;
	p->y += factor.y;
	p->z += factor.z;
}

void	ft_point_scale(t_point *p, float height, float scale)
{
	p->x *= scale;
	p->y *= scale;
	p->z *= scale;
	p->z *= height;
}
