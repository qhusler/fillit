/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:35:41 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/28 17:06:35 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	search(char **map, t_tet *tet, int size)
{
	int find;
	int i;
	int j;
	int k;

	find = 0;
	while (!find)
	{
		while (i < size)
		{
			while (j < size)
			{
				if (map[i][j] == '.')
					k++;
				j++;
			}
			j = 0;
			i++;
		}
	}
	return (0);
}

int		main()
{
	return (search());
}
