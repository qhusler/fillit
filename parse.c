/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:25:03 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/22 17:19:46 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**
**
*/

int		basic_test(char *file)
{
	int i;
	int c;

	i = -1;
	while (file[++i])
		if (file[i] != '.' && file[i] != '#' && file[i] != '\n')
			return (1);
	i = 4;
	c = 0;
	while (file[i])
	{
		if (file[i] != '\n' && file[i] != '\0')
			return (1);
		i += (c == 3) ? 6 : 5;
		c = (c == 3) ? 0 : c + 1;
	}
	return (0);
}

//int		medium_test()

int		main_parse(t_env *e)
{

	if (basic_test(e->file) == 1)
		error(1);
//	if (dieze_test(e->file) == 1)
//		error(1);
	return (EXIT_SUCCESS);
}
