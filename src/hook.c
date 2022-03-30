/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:13:15 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/30 16:31:30 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_lib/libft.h"
#include "../mlx/mlx.h"
#include "so_long.h"

int	closewin_h(t_gwin *gwin)
{
	clean_gwin(gwin);
	mlx_destroy_window(gwin->mlx, gwin->mlx_win);
	exit (0);
}

int	level_complete(t_gwin *gwin)
{
	gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col] = '0';
	gwin->gmap.exits = 224;
	return (0);
}

int	keydown_h(int keycode, t_gwin *gwin)
{
	if (keycode == KEY_ESC)
		return (closewin_h(gwin));
	if (gwin->gmap.exits < 0)
	{
		if (keycode == KEY_W)
			return (pl_move_up(gwin));
		else if (keycode == KEY_S)
			return (pl_move_down(gwin));
		else if (keycode == KEY_A)
			return (pl_move_left(gwin));
		else if (keycode == KEY_D)
			return (pl_move_right(gwin));
	}
	return (0);
}

int	render_h(t_gwin *gwin)
{
	if (!(gwin->frame % 25))
			gwin->render = 1;
	if (gwin->render)
	{
		update_window(gwin);
		gwin->render = 0;
		if (gwin->gmap.exits >= 0)
			draw_youwin(gwin);
	}
	gwin->frame = ++gwin->frame % 1000 ;
	return (0);
}
