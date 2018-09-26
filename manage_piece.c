/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 21:02:28 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/08 21:02:28 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_top_and_bottom(t_data *data, int x, int y, int distance)
{
	int map_y;

	map_y = y;
	y = y - distance < 0 ? 0 : y - distance;
	while ((x >= 0 && x < data->map_size_x) && data->map[x][y] &&
		y <= map_y + distance)
	{
		if (data->map[x][y] == (data->player == 'O' ? 'X' : 'O'))
			return (1);
		y++;
	}
	return (0);
}

int		check_left_and_right(t_data *data, int x, int y, int distance)
{
	int map_x;

	map_x = x;
	x = x - distance < 0 ? 0 : x - distance + 1;
	while (x < data->map_size_x && data->map[x][y] && x <= map_x + distance - 1)
	{
		if (data->map[x][y] == (data->player == 'O' ? 'X' : 'O'))
			return (1);
		x++;
	}
	return (0);
}

void	get_asterisk_distance(t_data *data, int map_x, int map_y, int distance)
{
	int enemies;

	data->piece_distance += distance;
	enemies = 0;
	enemies += check_top_and_bottom(data, map_x - distance, map_y, distance);
	enemies += check_top_and_bottom(data, map_x + distance, map_y, distance);
	enemies += check_left_and_right(data, map_x, map_y + distance, distance);
	enemies += check_left_and_right(data, map_x, map_y - distance, distance);
	if (!enemies && (distance < data->map_size_y ||
		distance < data->map_size_x))
		get_asterisk_distance(data, map_x, map_y, distance + 1);
}

void	get_piece_distance(t_data *data, int map_x, int map_y)
{
	int x;
	int y;

	x = 0;
	while (data->piece[x])
	{
		y = 0;
		while (data->piece[x][y])
		{
			if (data->piece[x][y] == '*')
				get_asterisk_distance(data, x + map_x, y + map_y, 1);
			y++;
		}
		x++;
	}
}

void	pick_the_best_piece(t_data *data, int map_x, int map_y)
{
	data->piece_distance = 0;
	get_piece_distance(data, map_x, map_y);
	if (!data->best_piece_distance ||
		(data->piece_distance < data->best_piece_distance))
	{
		data->best_piece_distance = data->piece_distance;
		data->best_x = map_x;
		data->best_y = map_y;
	}
}
