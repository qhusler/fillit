/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veriftetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:54:41 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/23 16:22:32 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	verifblock(char *map)
{
	int i;

	i = 0;
	while (i < 20)
	{
		ft_putchar(map[i]);
		i++;
	}
}

void	veriftetri(t_env *env)
{
	int	i;
	int descr;

	i = 0;
	descr = env->nb_tet;
	while (descr-- > 0)
	{
		verifblock(&env->file[i]);
		i += 20;
		if (descr > 0)
			ft_putchar(env->file[i]);
		i++;
	}	
}
