/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:08:42 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/25 12:30:11 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*get_tetriminos(char *s, int *i)
{
	if (s[*i] == '#' && s[*i + 1] == '#' && s[*i + 5] == '#' 
			&& s[*i + 6] == '#')
	{
		*i += 6;
		return ("##\n##");
	}
	if (s[*i] == '#' && s[*i + 1] == '#' && s[*i + 2] == '#' 
			&& s[*i + 3] == '#')
	{
		*i += 3;
		return ("####");
	}
	if (s[*i] == '#' && s[*i + 5] == '#' && s[*i + 10] == '#'
		   	&& s[*i + 15] == '#')
	{
		*i += 15;
		return ("#\n#\n#\n#");
	}
	
	return ();
}

int			mgt(t_env *e)
{
	int 	i;
	int		j;
	char	lettre;

	i = 0;
	j = 0;
	lettre = 'A';
	e->tetris = (t_tet*)malloc(sizeof(t_tet) * e->nb_tet);
	while (e->file[i])
	{
		if (e->file[i] == '#')
		{
			e->tetris[j].tet = ft_strdup(get_tetriminos(e->file, &i));
			e->tetris[j].id = lettre++;
//			printf("%s\n", e->tetris[j].tet);
//			printf("%c\n", e->tetris[j].id);
			j++;
		}
		i++;
	}
	return (0);
}
