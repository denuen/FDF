/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:33:38 by apintaur          #+#    #+#             */
/*   Updated: 2025/03/25 00:45:47 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char		*get_next_number(char *s);
static char		*ft_matrix_parsemap(t_mlx *data, char *tmp, int i);

void	ft_matrix_create_ff(t_mlx *data, char *filename)
{
	int		fd;
	int		i;
	char	*s;
	char	*tmp;

	ft_check_valid_pointer(data, data, "ft_matrix_create_ff");
	data->m.point = (t_point *) \
		malloc(sizeof(t_point) * (data->m.width * data->m.height));
	ft_check_valid_matrix(data, "ft_matrix_create_ff");
	ft_file_open(&fd, filename);
	s = get_next_line(fd);
	i = -1;
	while (s)
	{
		tmp = s;
		while (tmp && *tmp && *tmp != '\n' \
			&& ++i < (data->m.width * data->m.height))
			tmp = ft_matrix_parsemap(data, tmp, i);
		free (s);
		s = get_next_line(fd);
	}
	ft_matrix_extrema_xy(data);
	free (filename);
	ft_file_close(fd);
}

static char	*get_next_number(char *s)
{
	while (s && ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		s++;
	if (*(s + 1) == 'x' || *(s + 1) == 'X' || *(s + 1) == 'b')
		s += 2;
	while (s && ft_ishexa(*s))
		s++;
	if (s && (*s == '.' || *s == ','))
	{
		s++;
		while (ft_isspace(*s))
			s++;
		if (*(s + 1) == 'x' || *(s + 1) == 'X' || *(s + 1) == 'b')
			s += 2;
		while (s && ft_ishexa(*s))
			s++;
	}
	return (s);
}

static char	*ft_matrix_parsemap(t_mlx *data, char *tmp, int i)
{
	data->m.point[i].x = i % data->m.width;
	data->m.point[i].y = i / data->m.width;
	data->m.point[i].z = ft_atof_base(data, tmp);
	tmp = get_next_number(tmp);
	return (tmp);
}

void	ft_matrix_extrema_xy(t_mlx *data)
{
	t_point	i;

	data->m.max.x = data->m.point[0].x;
	data->m.max.y = data->m.point[0].y;
	data->m.min.x = data->m.max.x;
	data->m.min.y = data->m.max.y;
	i.y = -1;
	while (++i.y < data->m.height)
	{
		i.x = -1;
		while (++i.x < data->m.width)
		{
			i.z = data->m.point[(int)i.y * data->m.width + (int)i.x].x;
			if (i.z > data->m.max.x)
				data->m.max.x = i.z;
			if (i.z < data->m.min.x)
				data->m.min.x = i.z;
			i.z = data->m.point[(int)i.y * data->m.width + (int)i.x].y;
			if (i.z > data->m.max.y)
				data->m.max.y = i.z;
			if (i.z < data->m.min.y)
				data->m.min.y = i.z;
		}
	}
}

void	ft_matrix_extrema_z(t_mlx *data)
{
	int		x;
	int		y;
	float	z;

	y = -1;
	while (++y < data->m.height)
	{
		x = -1;
		while (++x < data->m.width)
		{
			z = data->m.point[y * data->m.width + x].z * data->op.height;
			if (z > data->m.max.z)
				data->m.max.z = z;
			if (z < data->m.min.z)
				data->m.min.z = z;
		}
	}
	if (data->m.min.z > 0.255f)
		data->m.min.z = 0.255f;
	if (data->m.min.z <= 0.0f)
		data->m.min.z *= -1;
	if (data->m.max.z <= 0.0f)
		data->m.max.z *= -1;
}
