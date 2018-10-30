/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:56:37 by mmervoye          #+#    #+#             */
/*   Updated: 2018/10/30 18:24:24 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				check_valid_line(char *line)
{
	int				ok;

	ok = 1;
	if (!ft_strncmp("Piece", line, 5))
	{
		usleep(140000);
		ft_putstr("\033[2J");
		ft_putstr("\033[H");
		return (1);
	}
	if (!ft_strncmp("Plateau", line, 7))
		return (1);
	while (*line)
	{
		if (*line == '*')
			return (1);
		if (*line != '.')
			ok = 0;
		line++;
	}
	return (ok);
}

void			start(void)
{
	char		*line;

	get_next_line(0, &line);
	get_next_line(0, &line);
	get_next_line(0, &line);
	get_next_line(0, &line);
	get_next_line(0, &line);
	get_next_line(0, &line);
	get_next_line(0, &line);
	get_next_line(0, &line);
	get_next_line(0, &line);
}

int				finish(char *line)
{
	ft_putstr("\033[0m");
	ft_putstr("\033[96m");
	ft_putstr(line);
	ft_putstr("\033[0m");
	free(line);
	get_next_line(0, &line);
	ft_putstr("\033[0m");
	ft_putstr("\n");
	ft_putstr("\033[94m");
	ft_putstr(line);
	ft_putstr("\n");
	ft_putstr("\033[0m");
	return (0);
}

int				main(void)
{
	char		*line;

	start();
	while (get_next_line(0, &line))
	{
		if (!ft_strncmp("==", line, 2))
			return (finish(line));
		if (*line == '<')
			continue ;
		if (check_valid_line(line))
			continue ;
		while (*line)
		{
			ft_putstr("\033[0m");
			if (*line == 'O' || *line == 'o')
				ft_putstr("\033[96m");
			else if (*line == 'X' || *line == 'x')
				ft_putstr("\033[94m");
			else
				ft_putstr("\033[90m");
			if (*line == 'X' || *line == 'x' || *line == 'O' || *line == 'O' || *line == 'o' || *line == '.')
				ft_putchar(*line);
			ft_putstr("\033[0m");
			line++;
		}
		ft_putchar('\n');
	}
	return (0);
}
