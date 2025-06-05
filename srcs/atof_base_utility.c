/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof_base_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:34:00 by apintaur          #+#    #+#             */
/*   Updated: 2025/02/06 10:02:43 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_atof_getdec(float *z, float *div, char *s)
{
	while (ft_isdigit(*s))
	{
		*z = *z * 10.0 + (float)(*s++ - '0');
		if (div && *z)
			*div *= 10.0;
	}
	return (s);
}

char	*ft_atof_gethexa(float *z, float *div, char *s)
{
	while (ft_ishexa(*s))
	{
		if (ft_islw(*s))
			*z = *z * 16.0 + (float)(*s++ - 87);
		else if (ft_isup(*s))
			*z = *z * 16.0 + (float)(*s++ - 55);
		else
			*z = *z * 10.0 + (float)(*s++ - '0');
	}
	if (div && *z)
		*div = pow(10.0, (floor (log10(*z) + 1)));
	return (s);
}

char	*ft_atof_getbin(float *z, float *div, char *s)
{
	while (*s == '0' || *s == '1')
		*z = *z * 2.0 + (float)(*s++ - '0');
	if (div && *z)
		*div = pow(10.0, (floor(log10(*z)) + 1));
	return (s);
}
