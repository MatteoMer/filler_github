/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:08:02 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/30 14:30:52 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		calculate_distance(t_filler *filler, int y, int x)
{
	int			i;
	int			j;
	int			tmp;

	i = -1;
	while (++i < filler->map_h)
	{
		j = -1;
		while (++j < filler->map_w)
		{
			if ((tmp = ft_distance(j, i, x, y)) < filler->map[i][j].heat_value || filler->map[i][j].heat_value == -1)
				filler->map[i][j].heat_value = tmp;
		}
	}
	return (0);
}

static int		fill_heatmap(t_filler *filler)
{
	int				i;
	int				j;

	i = -1;
	while (++i < filler->map_h)
	{
		j = -1;
		while (++j < filler->map_w)
		{
			if (filler->map[i][j].heat_value == 0 && filler->map[i][j].fill == filler->vilain_id)
				calculate_distance(filler, i, j);
			if (filler->map[i][j].heat_value == 0 && filler->map[i][j].fill == filler->player_id)
				filler->map[i][j].heat_value = -42;
		}
	}
	return (0);
}

int				exec(t_filler *filler)
{
	fill_heatmap(filler);
	filler->heat = -1;
	process(filler);
	/*
	if (filler->max_col > 42)
	{
		filler->co_x = 0;
		filler->co_y = 0;
	}
	if (filler->co_x == -1 || filler->co_y == -1)
	{
		filler->max_col++;
		exec(filler);
	}
	else
		filler->max_col = 1;
	*/
	return (0);
}
