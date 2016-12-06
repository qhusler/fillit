/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:13:04 by aguerin           #+#    #+#             */
/*   Updated: 2016/12/06 13:02:33 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(unsigned int size)
{
	char			**map;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!size)
		return (NULL);
	if (!(map = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (i < size)
	{
		j = 0;
		if (!(map[i] = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		while (j < size)
			map[i][j++] = '.';
		i++;
	}
	return (map);
}

char	**delete_map(char **map, unsigned int size)
{
	unsigned int i;

	i = -1;
	if (map)
	{
		while (++i < size)
			ft_strdel(&map[i]);
		free(map);
		map = NULL;
	}
	return (NULL);
}

void	map_copy(char **map, char **new, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			new[i][j] = map[i][j];
			j++;
		}
		i++;
		j = 0;
	}
}
