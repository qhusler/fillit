/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:35:13 by qhusler           #+#    #+#             */
/*   Updated: 2016/12/06 12:07:53 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	ft_sqrt_sup(unsigned int nb)
{
	unsigned int	ope;

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

void			print_map(char **map, int size)
{
	int i;

	i = 0;
	while (size > i)
		ft_putendl(map[i++]);
}

void			free_struct(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nb_tet)
	{
		ft_strdel(&e->tetris[i].tet);
		i++;
	}
	free(e->tetris);
	e->tetris = NULL;
}

int				main(int ac, char **av)
{
	t_env		e;
	char		**map;
	int			i;

	map = NULL;
	if (ac != 2)
		error(-1);
	i = 0;
	file_reader(&e, av[1]);
	main_parse(&e);
	init_tetris_struct(&e);
	e.map_size = ft_sqrt_sup(e.nb_tet * 4);
	while (!e.res)
	{
		map = delete_map(map, e.map_size);
		e.map_size += i++;
		map = create_map(e.map_size);
		place_piece(map, &e, 0);
	}
	print_map(e.res, e.map_size);
	map = delete_map(map, e.map_size);
	e.res = delete_map(e.res, e.map_size);
	free_struct(&e);
	return (0);
}
