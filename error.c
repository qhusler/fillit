/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:58:34 by qhusler           #+#    #+#             */
/*   Updated: 2016/11/21 18:36:44 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(int n)
{
	if (n == -1)
		ft_putstrc(CRED, "usage: fillit [file]\n", CEND);
	if (n == 0)
		ft_putstrc(CRED, "bad file descriptor\n", CEND);
	if (n == 1)
		ft_putstrc(CRED, "invalid file\n", CEND);
	exit(-1);
}
