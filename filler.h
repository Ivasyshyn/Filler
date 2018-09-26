/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:51:16 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/31 18:51:17 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_data
{
	char			player;
	int				map_size_x;
	int				map_size_y;
	char			**map;
	int				piece_size_x;
	int				piece_size_y;
	char			**piece;
	int				playing;
	int				piece_distance;
	int				best_piece_distance;
	int				best_x;
	int				best_y;
}					t_data;

void				get_player(t_data *data, char **line, int fd);
void				get_map_size(t_data *data, char **line, int fd);
void				get_map(t_data *data, char **line, int fd);
void				get_piece_size(t_data *data, char **line, int fd);
void				get_piece(t_data *data, char **line, int fd);
void				set_defaults(t_data *data);
void				clean_memory(t_data *data);
void				pick_the_best_piece(t_data *data, int map_x, int map_y);
int					patch_rt(int touches);
#endif
