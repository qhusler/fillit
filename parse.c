/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:25:03 by qhusler           #+#    #+#             */
/*   Updated: 2016/12/06 13:00:19 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				file_reader(t_env *e, char *param)
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

static int		basic_test(char *file)
{
	int i;
	int c;

	i = -1;
	c = 0;
	if (file[0] == '\0')
		return (1);
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

static int		medium_test(char *s, t_parse_info *pi, int ntet)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (s && s[i] && ntet--)
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
		if (pi->ndot != 12 || pi->mdi != 4 || pi->mnl != 4)
			return (1);
	}
	return (0);
}

static int		connect_test(char *s, t_parse_info *pi, int ntet)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (s && s[i] && ntet--)
	{
		i += 20;
		pi->nb_co = 0;
		while (j < i)
		{
			pi->nb_co += (s[j] == '#' && s[j + 1] == '#') ? 1 : 0;
			pi->nb_co += (s[j] == '#' && s[j - 1] == '#') ? 1 : 0;
			pi->nb_co += (s[j] == '#' && s[j + 5] == '#'
					&& (j + 5) < i) ? 1 : 0;
			pi->nb_co += (s[j] == '#' && s[j - 5] == '#'
					&& (j - 5) >= (i - 20)) ? 1 : 0;
			j++;
		}
		if (pi->nb_co != 6 && pi->nb_co != 8)
			return (1);
		i++;
		j++;
	}
	return (0);
}

int				main_parse(t_env *e)
{
	t_parse_info	pi;

	if (basic_test(e->file) == 1)
		error(1);
	if (medium_test(e->file, &pi, e->nb_tet) == 1)
		error(1);
	if (connect_test(e->file, &pi, e->nb_tet) == 1)
		error(1);
	return (EXIT_SUCCESS);
}
