/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:34:24 by apintaur          #+#    #+#             */
/*   Updated: 2025/02/06 10:02:43 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_ishexa(char c)
{
	return ((c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F') || ft_isdigit(c));
}

int	ft_isup(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_islw(char c)
{
	return (c >= 'a' && c <= 'z');
}
