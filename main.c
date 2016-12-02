/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:35:13 by qhusler           #+#    #+#             */
/*   Updated: 2016/12/02 14:38:09 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		file_reader(t_env *e, char *param)
{
	int		ret;
	int		fd;

	ret = 0;
	if ((fd = open(param, O_RDONLY)) < 0)
		error(0);
	ret = read(fd, e->file, 546);
	if (ret >= 546)
		error(1);
	e->file[ret] = '\0';
	close(fd);
	if (((ret - 20) % 21) != 0)
		error(1);
	e->nb_tet = ((ret - 20) / 21) + 1;
	return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
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
	/*map = create_map(181);
	map = delete_map(map, 181);
	if (!map)
		printf("%p, free ok\n", map);
	else
		printf("%p, free pas ok\n", map);
	//delete_map(map, 5);
*/	e.map_size = ft_sqrt_sup(e.nb_tet * 4);
  	while (!e.res)
	{
		e.map_size += i++;
		map = create_map(e.map_size);
		place_piece(map, &e, 0);
	}
	print_map(e.res, e.map_size);
	map = delete_map(e.res, e.map_size);
//	delete_map(map, e.map_size);
//	delete_map(e.res, e.map_size);*/
	return (0);
}
