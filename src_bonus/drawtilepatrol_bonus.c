/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawtilepatrol_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:34:58 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/29 23:23:44 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib/libft.h"
#include "../mlx/mlx.h"
#include "so_long_bonus.h"

int	mv_patrol_left(t_gwin *gwin, int x, int y)
{
	int	ret;

	ret = 1;
	gwin->gmap.map[y][x] = '0';
	if (gwin->gmap.map[y][x - 1] == 'P')
	{
		level_fail(gwin);
		x--;
	}
	else if (gwin->gmap.map[y][x - 1] == '0')
		x--;
	else if (mv_patrol_right(gwin, x, y))
		return (ret);
	else
		ret = 0;
	gwin->gmap.map[y][x] = GH_MOVELEFT;
	mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, \
	gwin->tile[TILE_GHOST], x * TILE_SZ, y * TILE_SZ);
	return (ret);
}

int	mv_patrol_right(t_gwin *gwin, int x, int y)
{
	int	ret;

	ret = 1;
	gwin->gmap.map[y][x] = '0';
	if (gwin->gmap.map[y][x + 1] == 'P')
	{
		level_fail(gwin);
		x++;
	}
	else if (gwin->gmap.map[y][x + 1] == '0')
		x++;
	else if (mv_patrol_left(gwin, x, y))
		return (ret);
	else
		ret = 0;
	gwin->gmap.map[y][x] = GH_MOVERIGHT;
	mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, \
	gwin->tile[TILE_GHOST], x * TILE_SZ, y * TILE_SZ);
	return (ret);
}

void	draw_patrol(t_gwin *gwin, int x, int y)
{
	int	sprite;

	draw_ground(gwin, x, y);
	sprite = (gwin->frame / 200) % 4;
	if (!sprite && gwin->gmap.map[y][x] == (GH_MOVELEFT + 3))
		mv_patrol_left(gwin, x, y);
	else if (!sprite && gwin->gmap.map[y][x] == (GH_MOVERIGHT + 3))
		mv_patrol_right(gwin, x, y);
	else
	{
		gwin->gmap.map[y][x] = GH_MOVELEFT + \
	(gwin->gmap.map[y][x] / GH_MOVERIGHT) * 4 + sprite;
		mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, \
		gwin->tile[TILE_GHOST + sprite], x * TILE_SZ, y * TILE_SZ);
	}
}
