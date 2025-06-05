/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:59:05 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/05 19:55:07 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

//Colors macros
# define MUTED_VIOLET		0xFF765FBD
# define INIGO_CLASSIC		0xFF4B0082
# define NEON_PINK			0xFFFF1493
# define ELECTRIC_PURPLE	0xFFBF00FF
# define BRIGHT_MAGENTA		0x014D4DFF
# define DEEP_PURPLE		0x017DF9FF

//Light utility
# define LIGHT_INTENSITY	0.3f
# define LIGHT_DEFLINE		0.1f
# define NORM_THRESHOLD		0.3f

typedef struct s_mlx	t_mlx;
typedef struct s_point	t_point;
typedef unsigned int	t_cc;

typedef struct s_gradient
{
	float	position;
	int		color;
}	t_gradient;

// Colors interpolation and mapping
t_cc	ft_color_interpolate(t_cc c1, t_cc c2, float t);
void	ft_color_map(t_mlx *data);

// Gradient and lighting functions [ colors_lighting.c ]
int		ft_color_get_gradient(t_gradient grad[5], float pos);
int		ft_color_getlight(int color, float height, t_point normal, \
							t_point light_dir);

// Color utility functions
t_cc	ft_lerp(int start, int end, float t);

#endif
