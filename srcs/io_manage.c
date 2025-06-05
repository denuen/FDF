/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:35:06 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/05 17:25:47 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_file_open(int *fd, char *filename)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0 || *fd > FOPEN_MAX)
	{
		perror("*Error: [in function ft_file_open] -> [invalid fd!]\n");
		free (filename);
		exit(EXIT_FAILURE);
	}
}

void	ft_file_close(int fd)
{
	if (fd < 0 || fd > FOPEN_MAX)
	{
		perror("*Error: [in function ft_file_close] -> [invalid fd!]\n");
		return ;
	}
	close (fd);
}

char	*ft_file_getname(t_mlx *data, char *s)
{
	char	*new;
	char	*tmp;
	size_t	size;

	new = ft_strdup(s);
	size = ft_strlen(s) + 1;
	if (!ft_strnstr(s, "./maps", size)
		&& !ft_strnstr(s, "maps/", size))
	{
		tmp = ft_strjoin("maps/", s);
		free (new);
		new = tmp;
	}
	if (!ft_strnstr(s, ".fdf", size))
	{
		tmp = ft_strjoin(new, ".fdf");
		free (new);
		new = tmp;
	}
	ft_check_valid_pointer(data, new, "ft_file_getname");
	return (new);
}
