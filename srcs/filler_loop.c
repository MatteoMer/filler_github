/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:28:49 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/30 14:31:10 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			insert_map_line(t_filler *filler, int i)
{
	char			*line;
	char			**tab;
	int				j;

	if (get_next_line(0, &line) == -1)
		return (-1);
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		return (-1);
	j = -1;
	while (++j < filler->map_w)
	{
		if (tab[1][j] == '.')
		{
			filler->map[i][j].fill = EMPTY;
			filler->map[i][j].heat_value = -1;
		}
		else if (tab[1][j] == 'O')
		{
			filler->map[i][j].fill = CIRCLE;
			filler->map[i][j].heat_value = 0;
		}
		else if (tab[1][j] == 'X')
		{
			filler->map[i][j].fill = CROSS;
			filler->map[i][j].heat_value = 0;
		}
		filler->map[i][j].x = j;
		filler->map[i][j].y = i;
	}
	return (0);
}

static int			init_map(t_filler *filler)
{
	int				i;
	char			*line;

	i = -1;
	filler->map = (t_point **)malloc(sizeof(t_point *) * filler->map_h);
	if (filler->map == NULL)
		return (-1);
	while (++i < filler->map_h)
	{
		if ((filler->map[i] = (t_point *)malloc(sizeof(t_point) * filler->map_w)) == NULL)
			return (-1);
	}
	get_next_line(0, &line);
	ft_strdel(&line);
	return (0);
}

static int			get_map(t_filler *filler, char **tab)
{
	int				i;

	i = -1;
	filler->map_h = ft_atoi(tab[1]);
	filler->map_w = ft_atoi(tab[2]);
	init_map(filler);
	while (++i < filler->map_h)
		insert_map_line(filler, i);
	return (0);
}

int					filler_loop(t_filler *filler)
{
	char		*line;
	char		**tab;

	filler->co_x = 0;
	filler->co_y = 0;
	while (get_next_line(0, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		if (!ft_strcmp("Plateau", tab[0]))
			get_map(filler, tab);
		else if (!ft_strcmp("Piece", tab[0]))
		{
			filler->heat = -1;
			filler->max_col = 1;
			get_piece(filler, tab);
			exec(filler);
			ft_printf("%d %d\n", filler->co_y, filler->co_x);
			if (filler)
				del_map(filler);
		}
		ft_deltab(&tab);
	}
	return (0);
}
