/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:01:29 by qhusler           #+#    #+#             */
/*   Updated: 2016/12/06 12:01:59 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	ft_strclr(e->file);
	e->res = NULL;
	return (0);
}
