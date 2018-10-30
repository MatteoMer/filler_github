/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:26:25 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/30 17:50:57 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			calculate_heat(t_filler *filler, int y, int x)
{
	t_point		p;
	int			heat;

	p.y = -1;
	heat = 0;
	while (++p.y < filler->piece_h)
	{
		p.x = -1;
		while (++p.x < filler->piece_w)
		{
			if (filler->map[y + p.y][x + p.x].heat_value != -42)
				heat += filler->map[y + p.y][x + p.x].heat_value;
		}
	}
	return (heat);
}

static int			check_heat(t_filler *filler)
{
	int				heat;
	int				x;
	int				y;

	x = filler->tmp_x;
	y = filler->tmp_y;
	heat = calculate_heat(filler, y, x);
	if (filler->heat == -1)
	{
		filler->co_x = x;
		filler->co_y = y;
		filler->heat = heat;
		return (0);
	}
	else if (filler->heat >= heat && filler->heat != -1)
	{
		filler->co_x = x;
		filler->co_y = y;
		filler->heat = heat;
		return (0);
	}
	return (0);
}

static int			try_piece(t_filler *filler, t_point *tmp)
{
	t_point			p;
	int				count;

	p.y = -1;
	count = 0;
	if (filler->piece_h + tmp->y > filler->map_h || filler->piece_w + tmp->x > filler\
->map_w)
		return (1);
	while (++p.y < filler->piece_h)
	{
		p.x = -1;
		while (++p.x < filler->piece_w)
		{
			if (filler->piece[p.y][p.x].fill == STAR && filler->map[tmp->y + p.y]\
[tmp->x + p.x].fill == filler->vilain_id)
				return (1);
			if (filler->piece[p.y][p.x].fill == STAR && filler->map[tmp->y + p.y]\
[tmp->x + p.x].fill == filler->player_id)
				count++;
		}
	}
	if (count == 0)
		return (1);
	return (count <= filler->max_col ? 0 : 1);
}

static int			find_place(t_filler *filler, int y, int x)
{
	t_point			pnt;
	t_point			tmp;

	pnt.y = -1;
	while (++pnt.y < filler->piece_h)
	{
		pnt.x = -1;
		while (++pnt.x < filler->piece_w)
		{
			tmp.x = x - pnt.x;
			tmp.y = y - pnt.y;
			if (filler->piece[pnt.y][pnt.x].fill == STAR && \
					(tmp.x >= 0 && tmp.y >= 0 && tmp.x < filler->map_w && tmp.y < filler->map_h) &&\
					try_piece(filler, &tmp) == 0)
			{
				filler->tmp_x = tmp.x;
				filler->tmp_y = tmp.y;
				return (0);
			}
		}
	}
	return (1);
}

int					process(t_filler *filler)
{
	int				i;
	int				j;

	i = -1;
	while (++i < filler->map_h)
	{
		j = -1;
		while (++j < filler->map_w)
		{
			if (filler->map[i][j].heat_value == -42)
			{
				if (find_place(filler, i, j) == 0)
					check_heat(filler);
			}
		}
	}
	return (0);
}
