/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 19:58:08 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/10 19:58:08 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	getmap_struct(t_mlx *e)
{
	size_t	y;

	y = 0;
	if (!(e->mapxyz = (int **)malloc((e->nbline) * sizeof(int *))))
		exit(EXIT_FAILURE);
	while (y < e->nbline)
	{
		e->mapxyz[y] = (int *)malloc(ft_strlen(e->map[0]) * sizeof(int));
		if (!(e->mapxyz[y]))
			exit(EXIT_FAILURE);
		y++;
	}
}

void	getmap_xy(t_mlx *e, size_t y, size_t x)
{
	int i;

	if (e->firstround == 0)
		getmap_struct(e);
	while (y < e->nbline)
	{
		i = 0;
		x = 0;
		while (e->map[y][i] != '\0')
		{
			if (e->map[y][i] == '.')
				e->mapxyz[y][x++] = 0;
			else if (e->map[y][i] == 'X')
				e->mapxyz[y][x++] = 1;
			else if (e->map[y][i] == 'x')
				e->mapxyz[y][x++] = 10;
			else if (e->map[y][i] == 'O')
				e->mapxyz[y][x++] = 2;
			else if (e->map[y][i] == 'o')
				e->mapxyz[y][x++] = 20;
			i++;
		}
		y++;
	}
}

int		prinf_if(t_mlx *e, char *line)
{
	if (e->print)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
	}
	return (1);
}

void	take_and_draw_map(t_mlx *e, char *line)
{
	if (e->takemap == 1)
	{
		e->mapjoin = ft_strjoin(e->mapjoin, &line[4]);
		e->mapjoin = ft_strjoin(e->mapjoin, "\n");
		e->nbline++;
		draw_score(e);
	}
	if (e->takemap == 2)
	{
		e->map = ft_strsplit(e->mapjoin, '\n');
		getmap_xy(e, 0, 0);
		box_drawing(e);
		mlx_do_sync(e->mlx);
		e->firstround = 1;
		e->takemap = 0;
		step_by_step(e);
	}
}

void	getlines(t_mlx *e)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (e->print)
		{
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
		}
		if (ft_strstr(line, "000"))
		{
			e->takemap = 1;
			e->nbline = 0;
			ft_strclr(e->mapjoin);
		}
		if (ft_strstr(line, "Piece"))
			e->takemap = 2;
		take_and_draw_map(e, line);
		if (ft_strstr(line, "<got (O)") && get_next_line(0, &line) > 0
			&& prinf_if(e, line) && ft_strstr(line, "Plateau"))
			e->score1++;
		if (ft_strstr(line, "<got (X)") && get_next_line(0, &line) > 0
			&& prinf_if(e, line) && ft_strstr(line, "Plateau"))
			e->score2++;
	}
}
