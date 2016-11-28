/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:08:42 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/28 18:48:58 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_tetriminos_j(char *s, int *i)
{
	if (s[*i + 5] == '#' && s[*i + 10] == '#' && s[*i + 11] == '#')
	{
		*i += 11;
		return ("#.\n#.\n##");
	}
	if (s[*i + 1] == '#' && s[*i + 2] == '#' && s[*i + 5] == '#')
	{
		*i += 5;
		return ("###\n#..");
	}
	if (s[*i + 1] == '#' && s[*i + 6] == '#' && s[*i + 11] == '#')
	{
		*i += 11;
		return ("##\n.#\n.#");
	}
	if (s[*i + 3] == '#' && s[*i + 4] == '#' && s[*i + 5] == '#')
	{
		*i += 5;
		return ("..#\n###");
	}
	return (get_tetriminos_z(s, i));
}

char	*get_tetriminos_l(char *s, int *i)
{
	if (s[*i + 1] == '#' && s[*i + 5] == '#' && s[*i + 10] == '#')
	{
		*i += 10;
		return ("##\n#.\n#.");
	}
	if (s[*i + 1] == '#' && s[*i + 2] == '#' && s[*i + 7] == '#')
	{
		*i += 7;
		return ("###\n..#");
	}
	if (s[*i + 5] == '#' && s[*i + 9] == '#' && s[*i + 10] == '#')
	{
		*i += 10;
		return (".#\n.#\n##");
	}
	if (s[*i + 5] == '#' && s[*i + 6] == '#' && s[*i + 7] == '#')
	{
		*i += 8;
		return ("#..\n###");
	}
	return (get_tetriminos_j(s, i));
}

char	*get_tetriminos(char *s, int *i)
{
	if (s[*i + 1] == '#' && s[*i + 5] == '#' && s[*i + 6] == '#')
	{
		*i += 6;
		return ("##\n##");
	}
	if (s[*i + 1] == '#' && s[*i + 2] == '#' && s[*i + 3] == '#')
	{
		*i += 3;
		return ("####");
	}
	if (s[*i + 5] == '#' && s[*i + 10] == '#' && s[*i + 15] == '#')
	{
		*i += 15;
		return ("#\n#\n#\n#");
	}
	return (get_tetriminos_l(s, i));
}

void	tet_cord(t_tet *tetris)
{
	int i;

	i = 0;
	while (tetris->tet[i] && tetris->tet[i] != '\n')
		i++;
	tetris->width = i;
	i = 0;
	tetris->heigh = 0;
	while (tetris->tet[i])
		if (tetris->tet[i++] == '\n')
			tetris->heigh++;
	tetris->heigh++;
}

int		init_tetris_struct(t_env *e)
{
	int		i;
	int		j;
	char	lettre;

	i = 0;
	j = 0;
	lettre = 'A';
	if (!(e->tetris = (t_tet*)malloc(sizeof(t_tet) * e->nb_tet)))
		return (1);
	while (e->file[i])
	{
		if (e->file[i] == '#')
		{
			e->tetris[j].id = lettre++;
			e->tetris[j].tet = ft_strdup(get_tetriminos(e->file, &i));
			tet_cord(&e->tetris[j]);
			j++;
		}
		i++;
	}
	return (0);
}
