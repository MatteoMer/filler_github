/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:23:30 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/30 17:12:11 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				del_map(t_filler *filler)
{
	int				i;

	i = -1;
	while (++i < filler->map_h)
		free(filler->map[i]);
	free(filler->map);
	return (0);
}

inline int						ft_distance(int x1, int y1, int x2, int y2)
{
	return (ft_sqrt(ft_pow(x2 - x1) + ft_pow(y2 - y1)));
}

inline int				ft_pow(int n)
{
	return (n * n);
}

int						ft_sqrt(int n)
{
	int			i;

	i = -1;
	while (++i <= n)
	{
		if (ft_pow(i) >= n)
			return (i);
	}
	return (0);
}


