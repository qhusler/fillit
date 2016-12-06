/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:21:46 by aguerin           #+#    #+#             */
/*   Updated: 2016/12/06 12:16:25 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>

typedef struct		s_parse_info
{
	int				ndot;
	int				mdi;
	int				mnl;
	int				nb_co;
}					t_parse_info;

typedef struct		s_tet
{
	char			*tet;
	char			id;
	int				width;
	int				heigh;
}					t_tet;

typedef struct		s_env
{
	char			file[546];
	int				nb_tet;
	t_tet			*tetris;
	int				map_size;
	char			**res;
}					t_env;

void				error(int n);
int					file_reader(t_env *e, char *param);
int					main_parse(t_env *env);
int					init_tetris_struct(t_env *e);
char				*get_tetriminos(char *s, int *i);

char				**create_map(unsigned int size);
void				place_piece(char **map, t_env *e, int k);
char				**delete_map(char **map, unsigned int size);


#endif
