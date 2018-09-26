/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:53:31 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/31 18:53:32 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "filler.h"

void	send_coordinates(int x, int y)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

int		suitable_size(t_data *data, int map_x, int map_y)
{
	if (data->map_size_x - map_x >= data->piece_size_x &&
		data->map_size_y - map_y >= data->piece_size_y)
		return (1);
	return (0);
}

int		valid_piece(t_data *data, int map_x, int map_y)
{
	int x;
	int y;
	int touches;

	touches = 0;
	x = 0;
	while (data->map[x + map_x] && data->piece[x])
	{
		y = 0;
		while (data->map[x + map_x][y + map_y] && data->piece[x][y])
		{
			if (data->piece[x][y] == '*' &&
				data->map[x + map_x][y + map_y] != '.')
			{
				if (data->map[x + map_x][y + map_y] == data->player)
					touches++;
				if (data->map[x + map_x][y + map_y] == (data->player == 'O' ?
					'X' : 'O'))
					return (0);
			}
			y++;
		}
		x++;
	}
	return (patch_rt(touches));
}

void	get_suitable_piece(t_data *data)
{
	int map_x;
	int map_y;

	map_x = 0;
	while (data->map[map_x])
	{
		map_y = 0;
		while (data->map[map_x][map_y])
		{
			if (suitable_size(data, map_x, map_y) &&
				valid_piece(data, map_x, map_y))
				pick_the_best_piece(data, map_x, map_y);
			map_y++;
		}
		map_x++;
	}
	send_coordinates(data->best_x, data->best_y);
	if (!data->piece_distance)
		data->playing = 0;
}

int		main(void)
{
	int		fd;
	char	*line;
	t_data	*data;

	fd = 0;
	data = (t_data*)malloc(sizeof(t_data));
	set_defaults(data);
	get_player(data, &line, fd);
	while (data->playing)
	{
		get_map(data, &line, fd);
		get_piece(data, &line, fd);
		get_suitable_piece(data);
		clean_memory(data);
	}
	free(data);
	return (0);
}
