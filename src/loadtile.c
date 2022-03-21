/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadtile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:47:02 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/22 00:07:33 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_lib/libft.h"
#include "../mlx/mlx.h"
#include "so_long.h"

/*
free gwin struct resource
gwin->mlx, ->mlxwin must be initiazed.
*/
void	clean_gwin(t_gwin *gwin)
{
	int	i;

	i = -1;
	while (++i < 42)
	{
		if (gwin->tile[i])
		{
			mlx_destroy_image(gwin->mlx, gwin->tile[i]);
			gwin->tile[i] = NULL;
		}
	}
	clean_map(&(gwin->gmap));
}

/*
!mlx_destroy_window leaks
*/
static int	ld_tilerr(t_gwin *gwin, char *err, int errnum)
{
	ft_putstr_fd(err, 2);
	clean_gwin(gwin);
	mlx_destroy_window(gwin->mlx, gwin->mlx_win);
	return (errnum);
}

int	ld_tile(t_gwin *gwin, int idx, char *path)
{
	int	pos[2];

	gwin->tile[idx] = mlx_xpm_file_to_image(gwin->mlx, path, &pos[0], &pos[1]);
	if (!gwin->tile[idx])
		return (0);
	return (1);
}

//	return (ld_tilerr(gwin, "Error\nTest error\n", 0));
int	loadtile(t_gwin *gwin)
{
	if (!ld_tile(gwin, TILE_GROUND, "data/ground.xpm"))
		return (ld_tilerr(gwin, "Error\nTile ground load error\n", 0));
	if (!ld_tile(gwin, TILE_WALL, "data/wall.xpm"))
		return (ld_tilerr(gwin, "Error\nTile wall load error\n", 0));
	if (!ld_tile(gwin, TILE_EXIT_CLOSED, "data/exit_closed.xpm"))
		return (ld_tilerr(gwin, "Error\nTile exit load error\n", 0));
	if (!ld_tile(gwin, TILE_EXIT_OPENED, "data/exit_opened.xpm"))
		return (ld_tilerr(gwin, "Error\nTile exit load error\n", 0));
	if (!ld_tile(gwin, TILE_COIN, "data/coin.xpm"))
		return (ld_tilerr(gwin, "Error\nTile coin load error\n", 0));
	if (!ld_tile(gwin, TILE_PLAYER, "data/player.xpm"))
		return (ld_tilerr(gwin, "Error\nTile player load error\n", 0));
	return (1);
}
