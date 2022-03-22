/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawtilemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:31:17 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/22 19:05:44 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib/libft.h"
#include "../mlx/mlx.h"
#include "so_long.h"

void	draw_ground(t_gwin *gwin, int x, int y)
{
	mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, gwin->tile[TILE_GROUND], \
	x * TILE_SZ, y * TILE_SZ);
}

void	draw_wall(t_gwin *gwin, int x, int y)
{
	mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, gwin->tile[TILE_WALL], \
	x * TILE_SZ, y * TILE_SZ);
}

void	draw_coin(t_gwin *gwin, int x, int y)
{
	draw_ground(gwin, x, y);
	mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, gwin->tile[TILE_COIN], \
	x * TILE_SZ, y * TILE_SZ);
}

void	draw_exit(t_gwin *gwin, int x, int y)
{
	if (gwin->gmap.coins == gwin->gmap.collected)
		mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, \
		gwin->tile[TILE_EXIT_OPENED], x * TILE_SZ, y * TILE_SZ);
	else
		mlx_put_image_to_window(gwin->mlx, gwin->mlx_win, \
		gwin->tile[TILE_EXIT_CLOSED], x * TILE_SZ, y * TILE_SZ);
}
