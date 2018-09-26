/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 19:58:08 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/10 19:58:08 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		get_color(t_mlx *e, int y, int x)
{
	if (e->mapxyz[y][x] == 1)
		return (0xffa500);
	else if (e->mapxyz[y][x] == 10)
		return (0xdc6900);
	else if (e->mapxyz[y][x] == 2)
		return (0x0099cc);
	else if (e->mapxyz[y][x] == 20)
		return (0x326ada);
	else
		return (0x000000);
}

void	draw_box(t_mlx *e, size_t tmpx, size_t x, size_t y)
{
	while (tmpx < ((x + 1) * 10))
		mlx_pixel_put(e->mlx, e->win, 110 + tmpx++, e->distance - 10 + (y * 10),
			get_color(e, y, x));
}

int		put_pixels(t_mlx *e, size_t y, size_t x)
{
	e->distance = 111;
	if ((e->mapxyz[y][x] >= e->mapxyz[y][x] ||
		e->mapxyz[y][x] < e->mapxyz[y][x]) && x < ft_strlen(e->map[y]))
		while (e->distance < 120)
		{
			draw_box(e, (x * 10) + 1, x, y);
			e->distance++;
		}
	return (++x);
}

void	box_drawing(t_mlx *e)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < e->nbline)
	{
		x = 0;
		while (x < ft_strlen(e->map[0]))
			x = put_pixels(e, y, x);
		y++;
	}
}

void	draw_score(t_mlx *e)
{
	char *scores;
	char *temp;

	mlx_clear_window(e->mlx, e->win);
	scores = ft_strjoin(e->p1, " score is ");
	temp = scores;
	scores = ft_strjoin(scores, ft_itoa(e->score1));
	mlx_string_put(e->mlx, e->win, 110, 30, 0x0099cc, scores);
	ft_strdel(&temp);
	ft_strdel(&scores);
	scores = ft_strjoin(e->p2, " score is ");
	temp = scores;
	scores = ft_strjoin(scores, ft_itoa(e->score2));
	mlx_string_put(e->mlx, e->win, 110, 50, 0xffa500, scores);
	ft_strdel(&temp);
	ft_strdel(&scores);
}
