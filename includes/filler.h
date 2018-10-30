/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:52:21 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/29 17:42:04 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# define EMPTY 0
# define CIRCLE 1
# define CROSS 2
# define STAR 3

typedef struct			s_point
{
	int					x;
	int					y;
	int					fill;
	int					heat_value;
}						t_point;

typedef struct			s_filler
{
	int					map_h;
	int					map_w;
	int					piece_h;
	int					piece_w;
	int					player_id;
	int					vilain_id;
	int					co_x;
	int					co_y;
	int					tmp_x;
	int					tmp_y;
	int					heat;
	int					max_col;
	t_point				**map;
	t_point				**piece;
}						t_filler;

int					get_player(t_filler *filler);
int					get_piece(t_filler *filler, char **tab);
int					filler_loop(t_filler *filler);
int					exec(t_filler *filler);
int					del_map(t_filler *filler);
int					process(t_filler *filler);

/*
** MATHS
*/

int						ft_pow(int n);
int						ft_sqrt(int n);
int						ft_distance(int x1, int y1, int x2, int y2);

#endif
