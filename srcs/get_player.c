/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:52:00 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/25 17:18:15 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					get_player(t_filler *filler)
{
	char		*line;
	char		**parse_tab;

	get_next_line(0, &line);
	parse_tab = ft_strsplit(line, ' ');
	if (!ft_strncmp("p1", parse_tab[2], 3))
	{
		filler->player_id = CIRCLE;
		filler->vilain_id = CROSS;
	}
	else
	{
		filler->player_id = CROSS;
		filler->vilain_id = CIRCLE;
	}
	ft_strdel(&line);
	ft_deltab(&parse_tab);
	return (0);
}
