/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 19:58:08 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/10 19:58:08 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H
# include <mlx.h>
# include "../filler.h"

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			distance;
	int			score1;
	int			score2;
	char		*p1;
	char		*p2;
	int			print;
	int			steps;
	size_t		winx;
	size_t		winy;
	int			start;
	int			firstround;
	int			**mapxyz;
	int			takemap;
	char		*sresulto;
	char		*sresultx;
	int			resulto;
	int			resultx;
	char		*mapjoin;
	char		**map;
	size_t		nbline;
}				t_mlx;

void			ft_getmap_xy(t_mlx *e, size_t y, size_t x);
void			box_drawing(t_mlx *e);
void			draw_score(t_mlx *e);
void			getlines(t_mlx *e);
char			*player_parsing(char *line, char *player);
int				keys(int keycode, t_mlx *e);
void			step_by_step(t_mlx *e);
#endif
