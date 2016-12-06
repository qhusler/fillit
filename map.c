/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:13:04 by aguerin           #+#    #+#             */
/*   Updated: 2016/12/06 12:16:17 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

char			**delete_map(char **map, unsigned int size)
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

int				search_place(char **map, int i, int j, t_tet *tet, int write)
{
	int	k;
	int jj;

	k = 0;
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

void		map_copy(char **map, char **new, int size)
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

void			place_piece(char **map, t_env *e, int k)
{
	int		i;
	int		j;
	char	**new;

	i = -1;
	j = -1;
	new = NULL;
	while (++i < e->map_size && !e->res)
	{
		while (++j < e->map_size && !e->res)
		{
			if (map[i][j] == '.' || e->tetris[k].tet[0] == '.')
			{
				if (i + e->tetris[k].heigh <= e->map_size
						&& j + e->tetris[k].width <= e->map_size)
				{
					if (search_place(map, i, j, &e->tetris[k], 0))
					{
						if (!new)
							new = create_map(e->map_size);
						map_copy(map, new, e->map_size);
						search_place(new, i, j, &e->tetris[k], 1);
						if (k < e->nb_tet - 1)
						{
							place_piece(new, e, k + 1);
						}
						else if (!(e->res))
						{
							e->res = create_map(e->map_size);
							map_copy(new, e->res, e->map_size);
						}
						new = delete_map(new, e->map_size);
					}
				}
			}
		}
		j = -1;
	}
}

/*void			place_piece(char **map, t_env *e, int k)
{
	int		i;
	int		j;
	char	**new;

	i = -1;
	j = -1;
	new = NULL;
	while (++i < e->map_size && !e->res)
	{
		while (++j < e->map_size && !e->res)
		{
			if (map[i][j] == '.' || e->tetris[k].tet[0] == '.')
			{
				if (i + e->tetris[k].heigh <= e->map_size
						&& j + e->tetris[k].width <= e->map_size)
				{
					if (search_place(map, i, j, &e->tetris[k], 0))
					{
						if (!new)
							new = create_map(e->map_size);
						map_copy(map, new, e->map_size);
						search_place(new, i, j, &e->tetris[k], 1);
						if (k < e->nb_tet - 1)
						{
							place_piece(new, e, k + 1);
						}
						else if (!(e->res))
						{
							e->res = create_map(e->map_size);
							map_copy(new, e->res, e->map_size);
						}
						new = delete_map(new, e->map_size);
					}
				}
			}
		}
		j = -1;
	}
}*/
