/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:48:30 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/05 17:25:47 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//Check utility[check_utility.c]
char	*ft_map_num_isvalid(char *s);
void	ft_check_valid_file_msg(char *s, int fd, char *filename);

void	ft_check_parameters(t_mlx *data, const char *signature)
{
	if (!data || !signature)
	{
		ft_printf("*Error: [in function %s] -> \
		invalid arguments!*\n", signature);
		exit (mymlx_destroy(data));
	}
}

void	ft_check_valid_pointer(t_mlx *data, void *p, const char *signature)
{
	ft_check_parameters(data, signature);
	if (!p)
	{
		ft_printf("*Error: [in function %s] -> \
		invalid pointer in ft_check_valid_type!*\n", signature);
		exit (mymlx_destroy(data));
	}
}

void	ft_check_valid_input(int argc, \
				char *argv[], const char *signature)
{
	ft_check_parameters((t_mlx *)signature, signature);
	if (argc != 2 || !argv || !argv[1])
	{
		ft_printf("*Error: [in function %s] -> [invalid input!]\n", signature);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_valid_file_skip(char *s, char *tmp, char *filename, t_utils *i)
{
	while (*tmp != '\n' && *tmp != '\0')
	{
		tmp = ft_map_num_isvalid(tmp);
		if (tmp == NULL)
			ft_check_valid_file_msg(s, (*i).x, filename);
		((*i).z)++;
	}
}

char	*ft_check_valid_file_ndot(char *s)
{
	s += 1;
	while (ft_isspace(*s))
		s++;
	if (!ft_strncmp(s, "0x", 2) || !ft_strncmp(s, "0X", 2))
	{
		s += 2;
		while (ft_ishexa(*s))
			s++;
	}
	else if (!ft_strncmp(s, "0b", 2))
	{
		s += 2;
		while (*s == '0' || *s == '1')
			s++;
	}
	else
		while (ft_isdigit(*s))
			s++;
	return (s);
}
