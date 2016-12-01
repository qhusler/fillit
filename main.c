/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:35:13 by qhusler           #+#    #+#             */
/*   Updated: 2016/12/01 10:04:54 by aguerin          ###   ########.fr       */
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

void	test_print(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nb_tet)
	{
		ft_putendl("....................");
		ft_putstr(e->tetris[i].tet);
		ft_putchar(10);
		ft_putchar(e->tetris[i].id);
		ft_putchar(10);
		ft_putstr("width = ");
		ft_putnbr(e->tetris[i].width);
		ft_putchar(10);
		ft_putstr("high = ");
		ft_putnbr(e->tetris[i].heigh);
		ft_putchar(10);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_env		e;
	char		**map;
	if (ac != 2)
		error(-1);

	file_reader(&e, av[1]);
	main_parse(&e);
	init_tetris_struct(&e);
	test_print(&e);

	e.map_size = ft_sqrt_sup(e.nb_tet * 4);
	map = create_map(e.map_size);
	place_piece(map, &e, 0);
	

//	print_map(map, e.map_size);
//	delete_map(map, e.map_size);
	return (0);
}
