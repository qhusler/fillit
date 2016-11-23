/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:35:13 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/23 18:27:06 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		file_reader(t_env *e, char *param)
{
	int		ret;
	int		fd;

	ret = 0;	
	fd = open(param, O_RDONLY);
	if (fd < 0)
		error(0);
	ret = read(fd, e->file, 546);
	if (ret >= 546)
		error(1);
	e->file[ret - 1] = '\0';
	close(fd);
	if (((ret - 20) % 21) != 0)				//if qui sert a savoir si le nb lu est valide.
		error(1);
	e->nb_tet = ((ret - 20) / 21) + 1;
	return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	t_env		e;

	if (ac != 2)
		error(-1);
	else
	{
		file_reader(&e, av[1]);
		main_parse(&e);
		veriftetri(&e);
	}
	return (0);
}
