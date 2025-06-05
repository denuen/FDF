/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 04:01:41 by apintaur          #+#    #+#             */
/*   Updated: 2025/01/14 12:58:07 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			i++;
	new = (char *) malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			new[i] = s[i];
			i++;
		}
	}
	new[i] = '\0';
	return (new);
}
