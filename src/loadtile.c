/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadtile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:47:02 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/18 20:00:52 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib/libft.h"
#include "../mlx/mlx.h"
#include "so_long.h"

int	ld_tilerr(t_gwin *gwin, char *err, int errnum)
{
	(void) gwin;
	ft_putstr_fd(err, 2);
	return (errnum);
}

static int	ld_tile(t_gwin *gwin, int idx, char *path)
{
	int	pos[2];

	gwin->tile[idx] = mlx_xpm_file_to_image(gwin->mlx, path, &pos[0], &pos[1]);
	if (!gwin->tile[idx])
		return (0);
	return (1);
}

int	loadtile(t_gwin *gwin)
{
	if (!ld_tile(gwin, TILE_GROUND, "data/ground.xpm"))
		return (ld_tilerr(gwin, "Error\nTile load error", 0));
	if (!ld_tile(gwin, TILE_WALL, "data/wall.xpm"))
		return (ld_tilerr(gwin, "Error\nTile load error", 0));
	if (!ld_tile(gwin, TILE_EXIT, "data/exit.xpm"))
		return (ld_tilerr(gwin, "Error\nTile load error", 0));
	if (!ld_tile(gwin, TILE_COIN, "data/coin.xpm"))
		return (ld_tilerr(gwin, "Error\nTile load error", 0));
	if (!ld_tile(gwin, TILE_PLAYER, "data/player.xpm"))
		return (ld_tilerr(gwin, "Error\nTile load error", 0));
	return (1);
}
