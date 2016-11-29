/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:13:04 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/29 17:42:51 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

unsigned int	ft_sqrt_sup(unsigned int nb)
{
	unsigned	int	ope;

	ope = 2;
	if (nb > 1)
	{
		while (ope * ope < nb)
			ope++;
		if (ope * ope >= nb)
			return (ope);
	}
	return (nb);
}

char			**create_map(unsigned int size)
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

void			delete_map(char **map, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (size > 0)
	{
		free(map[size - 1]);
		map[size] = NULL;
		size--;
	}
	free(map);
	map = NULL;
}

void			print_map(char **map, int size)
{
	int		i;

	i = 0;
	while (size > i)
		ft_putendl(map[i++]);
}

int 			place1(char **map, int i, int j, t_tet *tet, int write)
{
	int	k;
	int ii;
	int jj;

	k = 0;
	ii = i;
	jj = j;
	while (tet->tet[k])
	{
		if (map[i][j] != '.' && tet->tet[k] == '#')
			return (0);
		if (map[i][j] == '.' && tet->tet[k] == '#' && write)
			map[i][j] = tet->id;
		j++;
		k++;
		if (tet->tet[k] == '\n')
		{
			i++;
			k++;
			j = jj;
		}
	}
	return (1);
}

void			place_piece(char **map, t_env *e, t_tet *tet)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putchar(tet->id);
	ft_putchar('\n');
	while (i < e->map_size)
	{
		while (j < e->map_size)
		{
			if (map[i][j] == '.' || tet->tet[0] == '.')
			{
				if (i + tet->heigh <= e->map_size && j + tet->width <= e->map_size)
				{
					if (place1(map, i, j, tet, 0))
					{
						place1(map, i, j, tet, 1);
						print_map(map, e->map_size);
						return plac;
					}
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}
