/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:53:31 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/31 18:53:32 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "filler.h"

void	get_player(t_data *data, char **line, int fd)
{
	while (!data->player && get_next_line(fd, line))
	{
		if (ft_strstr(*line, "p1") && ft_strstr(*line, "sivasysh"))
			data->player = 'O';
		if (ft_strstr(*line, "p2") && ft_strstr(*line, "sivasysh"))
			data->player = 'X';
	}
}

void	get_map_size(t_data *data, char **line, int fd)
{
	while (get_next_line(fd, line))
	{
		if (ft_strstr(*line, "Plateau"))
		{
			data->map_size_x = ft_atoi((*line) + 8);
			data->map_size_y = ft_atoi((*line) + 8 +
				ft_ch_in_nb(data->map_size_x));
			break ;
		}
	}
}

void	get_map(t_data *data, char **line, int fd)
{
	int x;

	x = 0;
	get_map_size(data, line, fd);
	data->map = (char**)malloc(sizeof(char*) * data->map_size_x + 1);
	while (x < data->map_size_x && get_next_line(fd, line))
	{
		if (ft_strstr(*line, "    "))
			continue;
		data->map[x++] = ft_strdup(ft_strchr(*line, ' ') + 1);
	}
	data->map[x] = NULL;
}

void	get_piece_size(t_data *data, char **line, int fd)
{
	while (get_next_line(fd, line))
	{
		if (ft_strstr(*line, "Piece"))
		{
			data->piece_size_x = ft_atoi((*line) + 6);
			data->piece_size_y = ft_atoi((*line) + 6 +
				ft_ch_in_nb(data->piece_size_x));
			break ;
		}
	}
}

void	get_piece(t_data *data, char **line, int fd)
{
	int x;

	x = 0;
	get_piece_size(data, line, fd);
	data->piece = (char**)malloc(sizeof(char*) * data->piece_size_x + 1);
	while (x < data->piece_size_x && get_next_line(fd, line))
		data->piece[x++] = ft_strdup(*line);
	data->piece[x] = NULL;
}
