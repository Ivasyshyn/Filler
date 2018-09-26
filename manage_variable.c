/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 20:58:25 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/08 20:58:25 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_defaults(t_data *data)
{
	data->player = 0;
	data->map_size_x = 0;
	data->map_size_y = 0;
	data->map = NULL;
	data->piece_size_x = 0;
	data->piece_size_y = 0;
	data->piece = NULL;
	data->playing = 1;
	data->piece_distance = 0;
	data->best_piece_distance = 0;
	data->best_x = 0;
	data->best_y = 0;
}

void	ft_memdel_ar(char **array)
{
	int x;

	x = 0;
	while (array[x])
		ft_memdel((void*)&array[x++]);
}

void	clean_memory(t_data *data)
{
	ft_memdel_ar(data->piece);
	ft_memdel_ar(data->map);
	data->piece_distance = 0;
	data->best_piece_distance = 0;
	data->best_x = 0;
	data->best_y = 0;
	data->map = NULL;
	data->piece = NULL;
}

int		patch_rt(int touches)
{
	if (touches != 1)
		return (0);
	return (1);
}
