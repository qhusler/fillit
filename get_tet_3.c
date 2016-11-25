/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tet_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:55:44 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/25 15:48:07 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_tetriminos_t(char *s, int *i)
{
	if (s[*i + 4] == '#' && s[*i + 5] == '#' && s[*i + 6] == '#')
	{
		*i += 6;
		return (".#.\n###");
	}
	if (s[*i + 1] == '#' && s[*i + 2] == '#' && s[*i + 6] == '#')
	{
		*i += 6;
		return ("###\n.#.");
	}
	if (s[*i + 5] == '#' && s[*i + 6] == '#' && s[*i + 10] == '#')
	{
		*i += 10;
		return ("#.\n##\n#.");
	}
	if (s[*i + 4] == '#' && s[*i + 5] == '#' && s[*i + 10] == '#')
	{
		*i += 10;
		return (".#\n##\n.#");
	}
	return ("\0");
}

char	*get_tetriminos_z(char *s, int *i)
{
	if (s[*i + 1] == '#' && s[*i + 6] == '#' && s[*i + 7] == '#')
	{
		*i += 7;
		return ("##.\n.##");
	}
	if (s[*i + 4] == '#' && s[*i + 5] == '#' && s[*i + 9] == '#')
	{
		*i += 9;
		return (".#\n##\n#.");
	}
	if (s[*i + 1] == '#' && s[*i + 4] == '#' && s[*i + 5] == '#')
	{
		*i += 5;
		return (".##\n##.");
	}
	if (s[*i + 5] == '#' && s[*i + 6] == '#' && s[*i + 11] == '#')
	{
		*i += 11;
		return ("#.\n##\n.#");
	}
	return (get_tetriminos_t(s, i));
}
