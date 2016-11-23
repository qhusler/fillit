/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:21:46 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/23 18:49:03 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <stdio.h>//a delete plus tard
# include <fcntl.h>

typedef struct		s_env
{
	char			file[546];
	int				nb_tet;
}					t_env;

typedef struct		s_parse_info
{
	int				ndot;
	int				mdi;
	int				mnl;
}					t_parse_info;

void				error(int n);
int					main_parse(t_env *env);
void				veriftetri(t_env *env);

#endif
