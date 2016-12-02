/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:13:04 by aguerin           #+#    #+#             */
/*   Updated: 2016/12/02 10:03:56 by aguerin          ###   ########.fr       */
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

int				search_place(char **map, int i, int j, t_tet *tet, int write)
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

char			**map_copy(char **map, int size)
{
	char	**new;
	int		i;
	int		j;

	if (!(new = create_map(size)))
		return (NULL);
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
	return (new);
}

void			place_piece(char **map, t_env *e, int k)
{
	int		i;
	int		j;
	char	**new;

	i = -1;
	j = -1;
	while (++i < e->map_size)
	{
		while (++j < e->map_size)
		{
			if (map[i][j] == '.' || e->tetris[k].tet[0] == '.')
			{
				if (i + e->tetris[k].heigh <= e->map_size
					&& j + e->tetris[k].width <= e->map_size)
				{
					if (search_place(map, i, j, &e->tetris[k], 0))
					{
						new = map_copy(map, e->map_size);
						search_place(new, i, j, &e->tetris[k], 1);
						if (k < e->nb_tet - 1)
							place_piece(new, e, k + 1);
						else if (!(e->res))
							e->res = map_copy(new, e->map_size);
					
					}
				}
			}
		}
		j = -1;
	}
}
