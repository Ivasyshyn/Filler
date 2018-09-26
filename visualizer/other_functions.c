/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 19:58:08 by sivasysh          #+#    #+#             */
/*   Updated: 2018/07/10 19:58:08 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

char	*player_parsing(char *line, char *player)
{
	line = ft_strchr(line, '[');
	player = ft_strsub(line, 1, (ft_strchr(line, ']') - line));
	while (ft_strchr(player, '/'))
		player = ft_strchr(player, '/') + 1;
	if (ft_strchr(player, '.'))
		*ft_strchr(player, '.') = '\0';
	return (player);
}

int		keys(int keycode, t_mlx *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	if (keycode == 36 && e->start == 0)
		getlines(e);
	return (0);
}

void	step_by_step(t_mlx *e)
{
	if (e->steps)
	{
		mlx_hook(e->win, 2, 0, keys, e);
		mlx_loop(e->mlx);
	}
}
