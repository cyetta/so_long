/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawtilepers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:31:17 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/26 21:17:06 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib/libft.h"
#include "../mlx/mlx.h"
#include "so_long_bonus.h"

void	draw_player_animation(t_gwin *gwin)
{
	gwin->gmap.pl_move %= 3;
	if (gwin->gmap.pl_move)
	{
		mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, \
gwin->tile[TILE_PLAYER + gwin->gmap.pl_direction + gwin->gmap.pl_move], \
gwin->gmap.pl_col * TILE_SZ + (TILE_SZ / 3) * (gwin->gmap.pl_mv2col - \
gwin->gmap.pl_col) * gwin->gmap.pl_move, \
gwin->gmap.pl_row * TILE_SZ + (TILE_SZ / 3) * (gwin->gmap.pl_mv2row - \
gwin->gmap.pl_row) * gwin->gmap.pl_move);
		gwin->gmap.pl_move++;
	}
	else
	{
		gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col] = '0';
		gwin->gmap.pl_col = gwin->gmap.pl_mv2col;
		gwin->gmap.pl_row = gwin->gmap.pl_mv2row;
		gwin->gmap.map[gwin->gmap.pl_row][gwin->gmap.pl_col] = 'P';
		mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, \
gwin->tile[TILE_PLAYER + gwin->gmap.pl_direction], \
gwin->gmap.pl_col * TILE_SZ, gwin->gmap.pl_row * TILE_SZ);
	}
}

void	draw_player(t_gwin *gwin)
{
	if (!gwin->gmap.pl_move)
		mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, \
gwin->tile[TILE_PLAYER + gwin->gmap.pl_direction], \
gwin->gmap.pl_col * TILE_SZ, gwin->gmap.pl_row * TILE_SZ);
	else
		draw_player_animation(gwin);
}

int	draw_tile(t_gwin *gwin, char tile, int x, int y)
{
	if (tile == '0')
		draw_ground(gwin, x, y);
	else if (tile == '1')
		draw_wall(gwin, x, y);
	else if (tile == 'C')
		draw_coin(gwin, x, y);
	else if (tile == 'E')
		draw_exit(gwin, x, y);
	else if (tile == 'P')
		draw_ground(gwin, x, y);
	return (0);
}

void	draw_youwin(t_gwin *gwin)
{
	if ((gwin->gmap.exits / 25) % 2 == 0)
		mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, \
gwin->tile[TILE_YOUWIN], \
gwin->x_wind / 2 - 192, gwin->y_wind / 2 - 64);
	if (!--gwin->gmap.exits)
		closewin_h(gwin);
}

int	update_window(t_gwin *gwin)
{
	int	i;
	int	j;

	i = -1;
	while (++i < gwin->gmap.row)
	{
		j = -1;
		while (++j < gwin->gmap.col)
		{
			draw_tile(gwin, gwin->gmap.map[i][j], j, i);
		}
	}
	draw_player(gwin);
	return (0);
}
