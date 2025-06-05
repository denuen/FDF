/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:35:13 by apintaur          #+#    #+#             */
/*   Updated: 2025/02/06 10:02:43 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char *argv[])
{
	t_mlx		data;
	char		*filename;

	ft_check_valid_input(argc, argv, "main");
	filename = ft_file_getname(&data, argv[1]);
	ft_check_valid_file(&data, filename);
	mymlx_init(&data, filename);
	mlx_hook(data.pic.win.p, KeyPress, KeyPressMask, \
		mymlx_switch_keycode, &data);
	mlx_hook(data.pic.win.p, 17, 0, mymlx_exit, &data);
	mlx_loop_hook(data.mlx_p, mymlx_render, &data);
	mlx_loop(data.mlx_p);
	return (0);
}
