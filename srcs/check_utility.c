/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:34:37 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/05 17:25:47 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_map_num_firstdecimal(char *s);
char	*ft_map_num_firsthexa(char *s);
char	*ft_map_num_firstbin(char *s);
char	*ft_check_valid_file_ndot(char *s);

void	ft_check_valid_file_msg(char *s, int fd, char *filename)
{
	free (s);
	free (filename);
	ft_printf("*Error: [in function ft_check_valid_file] -> \
	invalid map format!*\n");
	ft_file_close(fd);
	exit(EXIT_FAILURE);
}

char	*ft_map_num_isvalid(char *s)
{
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		s += 1;
	if (ft_isdigit(*s))
	{
		if (*s == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X'))
			s = ft_map_num_firsthexa(s);
		else if (*s == '0' && *(s + 1) == 'b')
			s = ft_map_num_firstbin(s);
		else
			s = ft_map_num_firstdecimal(s);
	}
	else if (*s != '\n' && *s != '\0')
		return (NULL);
	return (s);
}

char	*ft_map_num_firstdecimal(char *s)
{
	while (ft_isdigit(*s))
		s++;
	if (*s == '.' || *s == ',')
		s = ft_check_valid_file_ndot(s);
	if ((!ft_isspace(*s) && *s != '\n' && *s != '\0') || !ft_ishexa(*(s - 1)))
		return (NULL);
	return (s);
}

char	*ft_map_num_firsthexa(char *s)
{
	s += 2;
	while (ft_ishexa(*s))
		s++;
	if (*s == '.' || *s == ',')
		s = ft_check_valid_file_ndot(s);
	if ((!ft_isspace(*s) && *s != '\n' && *s != '\0') || !ft_ishexa(*(s - 1)))
		return (NULL);
	return (s);
}

char	*ft_map_num_firstbin(char *s)
{
	s += 2;
	while (*s == '0' || *s == '1')
		s++;
	if (*s == '.' || *s == ',')
		s = ft_check_valid_file_ndot(s);
	if ((!ft_isspace(*s) && *s != '\n' && *s != '\0') || !ft_ishexa(*(s - 1)))
		return (NULL);
	return (s);
}
