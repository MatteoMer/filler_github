/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:39:21 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/30 14:20:38 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			insert_piece_line(t_filler *filler, int i)
{
	char			*line;
	int				j;

	if (get_next_line(0, &line) == -1)
		return (-1);
	j = -1;
	while (++j < filler->piece_w)
	{
		if (line[j] == '.')
			filler->piece[i][j].fill = EMPTY;
		else if (line[j] == '*')
			filler->piece[i][j].fill = STAR;
		filler->piece[i][j].x = j;
		filler->piece[i][j].y = i;
	}
	return (0);
}

static int			init_piece(t_filler *filler)
{
	int				i;

	i = -1;
	filler->piece = (t_point **)malloc(sizeof(t_point *) * filler->piece_h);
	if (filler->piece == NULL)
		return (-1);
	while (++i < filler->piece_h)
	{
		if ((filler->piece[i] = (t_point *)malloc(sizeof(t_point) * filler->piece_w)) == NULL)
			return (-1);
	}
	return (0);
}

int					get_piece(t_filler *filler, char **tab)
{
	int			i;

	i = -1;
	filler->piece_h = ft_atoi(tab[1]);
	filler->piece_w = ft_atoi(tab[2]);
	init_piece(filler);
	while (++i < filler->piece_h)
		insert_piece_line(filler, i);
	return (0);
}
