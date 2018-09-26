/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sivasysh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 19:58:08 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/10 19:58:08 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	get_window_size(t_mlx *e)
{
	char	*line;
	int		y;
	int		x;

	while (get_next_line(0, &line) > 0)
		if (ft_strcmp(ft_strsub(line, 0, 7), "Plateau") == 0)
		{
			y = ft_atoi((line) + 8);
			x = ft_atoi((line) + 8 + ft_ch_in_nb(y));
			e->winy = (y * 10) + 210;
			e->winx = (x * 10) + 210;
			break ;
		}
}

void	get_players(t_mlx *e)
{
	char *line;

	while (!(e->p1 && e->p2) && get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "p1"))
			e->p1 = player_parsing(line, e->p1);
		if (ft_strstr(line, "p2"))
			e->p2 = player_parsing(line, e->p2);
	}
}

void	set_default_values(t_mlx *e)
{
	e->print = 0;
	e->steps = 0;
	e->p1 = NULL;
	e->p2 = NULL;
	e->winx = 1000;
	e->winy = 1000;
	e->score1 = 0;
	e->score2 = 0;
	e->start = 0;
	e->takemap = 0;
	e->nbline = 0;
	e->firstround = 0;
	e->sresulto = "\0";
	e->sresultx = "\0";
	e->mapjoin = "\0";
}

void	set_parameters(t_mlx *e, int argc, char **argv)
{
	if (argc > 1)
	{
		while (argc-- > 1)
		{
			if (ft_strchr(argv[argc], 'p'))
				e->print = 1;
			if (ft_strchr(argv[argc], 's'))
				e->steps = 1;
		}
	}
}

int		main(int argc, char **argv)
{
	t_mlx e;

	set_default_values(&e);
	set_parameters(&e, argc, argv);
	get_players(&e);
	get_window_size(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.winx, e.winy,
		"Filler visualizer by sivasysh");
	mlx_string_put(e.mlx, e.win, e.winx / 2 - 100, e.winy / 2, 0xFFFFFF,
		"Press Enter to start");
	mlx_hook(e.win, 2, 0, keys, &e);
	mlx_loop(e.mlx);
}
