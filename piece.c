/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:12:34 by aguerin           #+#    #+#             */
/*   Updated: 2016/12/06 13:12:36 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		search_place(char **map, int *ij, t_tet *tet, int write)
{
	int i;
	int	j;
	int	k;
	int jj;

	k = 0;
	i = ij[0];
	j = ij[1];
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

void	search(char **map, t_env *e, int *ij)
{
	char **new;

	new = NULL;
	if (search_place(map, ij, &e->tetris[ij[2]], 0))
	{
		if (!new)
			new = create_map(e->map_size);
		map_copy(map, new, e->map_size);
		search_place(new, ij, &e->tetris[ij[2]], 1);
		if (ij[2] < e->nb_tet - 1)
			place_piece(new, e, ij[2] + 1);
		else if (!(e->res))
		{
			e->res = create_map(e->map_size);
			map_copy(new, e->res, e->map_size);
		}
		new = delete_map(new, e->map_size);
	}
}

void	place_piece(char **map, t_env *e, int k)
{
	int		i;
	int		j;
	int		ij[3];

	i = -1;
	j = -1;
	while (++i < e->map_size && !e->res)
	{
		while (++j < e->map_size && !e->res)
		{
			if (map[i][j] == '.' || e->tetris[k].tet[0] == '.')
			{
				if (i + e->tetris[k].heigh <= e->map_size
						&& j + e->tetris[k].width <= e->map_size)
				{
					ij[0] = i;
					ij[1] = j;
					ij[2] = k;
					search(map, e, ij);
				}
			}
		}
		j = -1;
	}
}
