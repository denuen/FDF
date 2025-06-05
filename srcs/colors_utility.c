/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:28:27 by apintaur          #+#    #+#             */
/*   Updated: 2025/03/25 00:52:26 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned int	ft_lerp(int start, int end, float t)
{
	return ((unsigned int)(start + t * (end - start)));
}

void	ft_palette_init(t_gradient palette[6])
{
	palette[0].position = 0.0f;
	palette[0].color = MUTED_VIOLET;
	palette[1].position = 0.2f;
	palette[1].color = INIGO_CLASSIC;
	palette[2].position = 0.4f;
	palette[2].color = NEON_PINK;
	palette[3].position = 0.6f;
	palette[3].color = ELECTRIC_PURPLE;
	palette[4].position = 0.8f;
	palette[4].color = BRIGHT_MAGENTA;
	palette[5].position = 1.0f;
	palette[5].color = DEEP_PURPLE;
}

void	ft_normalize_z(float norm_threshold, float *z)
{
	float	high_range;

	high_range = (*z - norm_threshold) / (1.0f - norm_threshold);
	high_range = powf(high_range, 0.85f);
	*z = norm_threshold + high_range * (1.0f - norm_threshold);
	*z = (*z * 0.95f) + 0.025f;
	*z = fmaxf(0.0f, fminf(1.0f, *z));
}
