/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:25:03 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/23 18:11:35 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		basic_test(char *file)
{
	int i;
	int c;

	i = -1;
	c = 0;
	while (file[++i])
		if (file[i] != '.' && file[i] != '#' && file[i] != '\n')
			return (1);
	i = 4;
	c = 0;
	while (file[i])
	{
		if (file[i] != '\n')
			return (1);
		i += (c == 3) ? 6 : 5;
		c += (c == 4) ? 0 : 1;
		if (c == 4 && file[i] == 0)
			return (0);
		c = (c == 4) ? 0 : c;
	}
	return (0);
}

int		medium_test(char *s, t_parse_info *pi, int ntet)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (s && s[i] && ntet != 0)
	{
		i += 20;
		pi->ndot = 0;
		pi->mdi = 0;
		pi->mnl = 0;
		while (j < i)
		{
			pi->ndot += (s[j] == '.') ? 1 : 0;
			pi->mdi += (s[j] == '#') ? 1 : 0;
			pi->mnl += (s[j] == '\n') ? 1 : 0;
			j++;
		}
		i++;
		j++;
		ntet--;
		if (pi->ndot != 12 || pi->mdi != 4 || pi->mnl != 4)
			return (1);
	}
	return (0);
}

int		main_parse(t_env *e)
{
	t_parse_info	pi;

	if (basic_test(e->file) == 1)
		error(1);
	if (medium_test(e->file, &pi, e->nb_tet) == 1)
		error(1);
	ft_putstrc(CGREEN, "valid\n", CEND);
	return (EXIT_SUCCESS);
}
