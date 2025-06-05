/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:34:08 by apintaur          #+#    #+#             */
/*   Updated: 2025/02/06 10:02:43 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_atof_firstdec(float *z, char *s);
static void	ft_atof_firsthexa(float *z, char *s);
static void	ft_atof_firstbin(float *z, char *s);

//Atof_base utility [atof_base_utility.c]
char		*ft_atof_getdec(float *z, float *div, char *s);
char		*ft_atof_gethexa(float *z, float *div, char *s);
char		*ft_atof_getbin(float *z, float *div, char *s);

float	ft_atof_base(t_mlx *data, const char *s)
{
	float	z;
	int		sign;

	(void)data;
	z = 0.0f;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (s && (*s == '+' || *s == '-'))
		sign = 1 - 2 * (*s++ == '-');
	if (ft_isdigit(*s))
	{
		if (*s == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X'))
			ft_atof_firsthexa(&z, (char *)s);
		else if (*s == '0' && *(s + 1) == 'b')
			ft_atof_firstbin(&z, (char *)s);
		else
			ft_atof_firstdec(&z, (char *)s);
	}
	return (z * sign);
}

static void	ft_atof_firstdec(float *z, char *s)
{
	float	tmp_z;
	float	div;

	tmp_z = 0.0f;
	div = 1.0f;
	s = ft_atof_getdec(z, NULL, s);
	if (*s == '.' || *s == ',')
	{
		s += 1;
		while (ft_isspace(*s))
			s++;
		if (*(s + 1) && (!ft_strncmp(s, "0x", 2) || !ft_strncmp(s, "0X", 2)))
			s = ft_atof_gethexa(&tmp_z, &div, s + 2);
		else if (*(s + 1) && !ft_strncmp(s, "0b", 2))
			s = ft_atof_getbin(&tmp_z, &div, s + 2);
		else
			s = ft_atof_getdec(&tmp_z, &div, s);
		*z += (tmp_z / div);
	}
}

static void	ft_atof_firsthexa(float *z, char *s)
{
	float	tmp_z;
	float	div;

	s += 2;
	tmp_z = 0.0f;
	div = 1.0f;
	s = ft_atof_gethexa(z, NULL, s);
	if (*s == '.' || *s == ',')
	{
		s += 1;
		while (ft_isspace(*s))
			s++;
		if (!ft_strncmp(s, "0x", 2) || !ft_strncmp(s, "0X", 2))
			s = ft_atof_gethexa(&tmp_z, &div, s + 2);
		else if (!ft_strncmp(s, "0b", 2))
			s = ft_atof_getbin(&tmp_z, &div, s + 2);
		else
			s = ft_atof_getdec(&tmp_z, &div, s);
		*z += (tmp_z / div);
	}
}

static void	ft_atof_firstbin(float *z, char *s)
{
	float	tmp_z;
	float	div;

	s += 2;
	tmp_z = 0.0f;
	div = 1.0f;
	s = ft_atof_getbin(z, NULL, s);
	if (*s == '.' || *s == ',')
	{
		s += 1;
		while (ft_isspace(*s))
			s++;
		if (!ft_strncmp(s, "0x", 2) || !ft_strncmp(s, "0X", 2))
			s = ft_atof_gethexa(&tmp_z, &div, s + 2);
		else if (!ft_strncmp(s, "0b", 2))
			s = ft_atof_getbin(&tmp_z, &div, s + 2);
		else
			s = ft_atof_getdec(&tmp_z, &div, s);
		*z += (tmp_z / div);
	}
}
