/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:34:31 by apintaur          #+#    #+#             */
/*   Updated: 2025/02/06 10:02:43 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_check_valid_file_msg(char *s, int fd, char *filename);
void	ft_check_valid_file_skip(char *s, char *tmp, \
						char *filename, t_utils *i);

void	ft_check_valid_file(t_mlx *data, char *filename)
{
	t_utils	i;
	char	*s;
	char	*tmp;

	ft_check_parameters(data, __func__);
	ft_check_parameters((t_mlx *)filename, __func__);
	ft_file_open(&i.x, filename);
	s = get_next_line(i.x);
	data->m.width = 0;
	data->m.height = 0;
	while (s)
	{
		i.z = 0;
		tmp = s;
		ft_check_valid_file_skip(s, tmp, filename, &i);
		data->m.width += i.z * (!data->m.width);
		if (data->m.width != i.z)
			ft_check_valid_file_msg(s, i.x, filename);
		data->m.height++;
		free (s);
		s = get_next_line(i.x);
	}
	ft_file_close(i.x);
}

void	ft_check_valid_mlx(t_mlx *data, const char *signature)
{
	ft_check_parameters(data, signature);
	if (!data->mlx_p)
	{
		ft_printf("*Error: [in function %s] -> \
		invalid mlx_pointer!*\n", signature);
		exit (mymlx_destroy(data));
	}
	if (!data->pic.img.p)
	{
		ft_printf("*Error: [in function %s] -> \
		invalid mlx_img_pointer!*\n", signature);
		exit(mymlx_destroy(data));
	}
	if (!data->pic.win.p)
	{
		ft_printf("*Error: [in function %s] -> \
		invalid mlx_win_pointer!*\n", signature);
		exit(mymlx_destroy(data));
	}
	if (!data->pic.img.addr || data->pic.img.bits_per_pixel < 0)
	{
		ft_printf("*Error: [in function %s] -> \
		invalid image addictional!*\n", signature);
		exit (mymlx_destroy(data));
	}
}

void	ft_check_valid_matrix(t_mlx *data, const char *signature)
{
	ft_check_parameters(data, signature);
	if (!data->m.point)
	{
		ft_printf("*Error: [in function %s] -> \
		invalid matrix pointer!\n");
		exit(mymlx_destroy(data));
	}
	if ((data->m.height * data->m.width) == 0)
	{
		ft_printf("*Error: [in function %s] -> \
		invalid matrix size!\n");
		exit(mymlx_destroy(data));
	}
}
